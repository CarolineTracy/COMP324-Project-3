(* C- interpreter.
 *
 * N. Danner
 *)


(* Raised when a function body terminates without executing `return`.
 *)
exception NoReturn of Ast.Id.t

(* MultipleDeclaration x is raised when x is declared more than once in a
 * block.
 *)
exception MultipleDeclaration of Ast.Id.t

(* UnboundVariable x is raised when x is used but not declared.
 *)
exception UnboundVariable of Ast.Id.t

(* UndefinedFunction f is raised when f is called but has not been defined.
 *)
exception UndefinedFunction of Ast.Id.t

(* TypeError s is raised when an operator or function is applied to operands
 * of the incorrect type.  s is any (hopefuly useful) message.
 *)
exception TypeError of string

(* OutOfMemoryError is raised when the an attempt is made to allocate more
 * space in the store than is available.
 *)
exception OutOfMemoryError

(* Raised when an attempt is made to access a store location that is
 * negative or larger than the store capacity.
 *)
exception SegmentationError of int


(* Values.
 *)
module Value = struct
  type t = 
    | V_Undefined
    | V_None
    | V_Int of int
    | V_Bool of bool
    | V_Str of string
    [@@deriving show]

  (* to_string v = a string representation of v (more human-readable than
   * `show`.
   *)
  let to_string (v : t) : string =
    match v with
    | V_Undefined -> "?"
    | V_None -> "None"
    | V_Int n -> Int.to_string n
    | V_Bool b -> Bool.to_string b
    | V_Str s -> s
end

(* Module for input/output built-in functions.
 *
 * Alas, this module needs to be defined as part of the Interp module, because
 * the I/O functions rely on Value.t.  I guess the right way to do this is for
 * [fprintf] to take a list of metalanguage type values, and for [fscanf] to
 * return a disjoint sum of metalanguage type values, and let the caller
 * unpack/pack from/to [Value.t] values.
 *)
module Io = struct

  (* The input source and output destination is abstracted, because there
   * are two use cases that are rather different.  The interactive
   * interpreter uses standard input and standard output for input and
   * output.  But the automated tests need the input source and output
   * destination to be programmatic values (the former is read from a test
   * specification, and the latter has to be compared to the test
   * specification).  The "right" way to do this is to make the interpreter
   * itself a functor that takes an IO module as an argument, but that is a
   * little much for this project, so instead we define this Io module with
   * the input source (`in_channel`) and output destination (`output`)
   * references that can be changed by the client that is using the
   * interpreter.
   *)

  (* The input channel.  get_* and prompt_* read from this channel.  Default
   * is standard input.
   *)
  let in_channel : Scanf.Scanning.in_channel ref =
    ref Scanf.Scanning.stdin

  (* The output function.  printf calls this function for output.  Default is
   * to print the string to standard output and flush.
   *)
  let output : (string -> unit) ref = 
    ref (
      fun s ->
        Out_channel.output_string Out_channel.stdout s ;
        Out_channel.flush Out_channel.stdout
    )

  (* tail s = s[1..].
   *)
  let tail (s : string) : string =
    String.sub s 1 (String.length s - 1)

  (* tailtail s = tail(tail s).
   *)
  let tailtail (s : string) : string =
    tail (tail s)

  (* scons c s = String.make 1 c ^ s.
   *)
  let scons (c : char) (s : string) : string =
    String.make 1 c ^ s

  (* do_fprintf fmt vs:  print [vs] to stdout according to [fmt].
   *)
  let do_fprintf (fmt : string) (vs : Value.t list) : unit =
    let rec build_result (fmt : string) (vs : Value.t list) : string =
      if fmt = "" 
      then
        match vs with
        | [] -> ""
        | _ -> raise @@ TypeError "Too many values to print for format string"
      else if fmt.[0] != '%' then scons fmt.[0] (build_result (tail fmt) vs)
      else if String.length fmt = 1
      then raise @@ TypeError "Malformed format string (incomplete %)"
      else
        match (String.sub fmt 0 2, vs) with
        | ("%d", V_Int n :: vs) -> 
          Printf.sprintf
            "%d%s"
            n
            (build_result (tailtail fmt) vs)
        | ("%b", V_Bool b :: vs) -> 
          Printf.sprintf
            "%b%s"
            b
            (build_result (tailtail fmt) vs)
        | ("%s", V_Str s :: vs) -> 
          Printf.sprintf
            "%s%s"
            s
            (build_result (tailtail fmt) vs)
        | _ ->
          raise @@ TypeError "Bad % specifier or incorrect value type"
    in

    !output (build_result fmt vs)

  (* do_fscanf fmt = v, where v is the value read from stdin according to fmt.
   *)
  let do_fscanf (fmt : string) : Value.t =
    let fmt' : string = String.trim fmt in
    match fmt' with
    | "%d" -> Value.V_Int (Scanf.bscanf !in_channel " %d" (fun n -> n))
    | "%b" -> Value.V_Bool (Scanf.bscanf !in_channel " %b" (fun b -> b))
    | "%s" -> Value.V_Str (Scanf.bscanf !in_channel " %s" (fun s -> s))
    | _ ->
      raise @@ TypeError (
        Printf.sprintf
        "Bad scanf format string: %s"
        fmt
      )

end

(* Module for environments. We will use ρ as a metavariable over environments.
 *)
module Env = struct

  type env = (Ast.Id.t * Value.t) list
  type t = env list

  let empty : t = [[]]

  let from_list (rho : t) : t = rho

  let push (rho : t) : t =
    [] :: rho

  let pop (rho : t) : t =
    match rho with
    | [] -> failwith "pop on empty environment stack"
    | _ :: rest -> rest

  let rec lookup (rho : t) (x : Ast.Id.t) : Value.t =
    match rho with
    | [] -> raise (UnboundVariable x)
    | scope :: rest ->
        match List.assoc_opt x scope with
        | Some v -> v
        | None -> lookup rest x

  let declare (rho : t) (x : Ast.Id.t) (v : Value.t) : t =
    match rho with
    | [] -> failwith "declare on empty environment stack"
    | scope :: rest ->
        if List.mem_assoc x scope then
          raise (MultipleDeclaration x)
        else
          ((x, v) :: scope) :: rest

  let rec assign (rho : t) (x : Ast.Id.t) (v : Value.t) : t =
    match rho with
    | [] -> raise (UnboundVariable x)
    | scope :: rest ->
        if List.mem_assoc x scope then
          ((x, v) :: List.remove_assoc x scope) :: rest
        else
          scope :: assign rest x v

end



module Frame = struct
  type t =
    | Envs of Env.t
    | Return of Value.t
end

(*  binop op v v' = v'', where v'' is the result of applying the semantic
 *  denotation of `op` to `v` and `v''`.
 *)
let binop (op : Ast.Expr.binop) (v : Value.t) (v' : Value.t) : Value.t =
  match (op, v, v') with
  | (Ast.Expr.Plus, Value.V_Int n, Value.V_Int n') -> Value.V_Int (n + n')
  | (Ast.Expr.Minus, Value.V_Int n, Value.V_Int n') -> Value.V_Int (n - n')
  | (Ast.Expr.Times, Value.V_Int n, Value.V_Int n') -> Value.V_Int (n * n')
  | (Ast.Expr.Div, Value.V_Int n, Value.V_Int n') -> Value.V_Int (n / n')
  | (Ast.Expr.Mod, Value.V_Int n, Value.V_Int n') -> Value.V_Int (n mod n')
  | (Ast.Expr.And, Value.V_Bool b, Value.V_Bool b') -> Value.V_Bool (b && b')
  | (Ast.Expr.Or, Value.V_Bool b, Value.V_Bool b') -> Value.V_Bool (b || b')
  | (Ast.Expr.Eq, Value.V_Int n, Value.V_Int n') -> Value.V_Bool (n = n')
  | (Ast.Expr.Eq, Value.V_Bool b, Value.V_Bool b') -> Value.V_Bool (b = b')
  | (Ast.Expr.Ne, Value.V_Int n, Value.V_Int n') -> Value.V_Bool (n != n')
  | (Ast.Expr.Ne, Value.V_Bool b, Value.V_Bool b') -> Value.V_Bool (b != b')
  | (Ast.Expr.Lt, Value.V_Int n, Value.V_Int n') -> Value.V_Bool (n < n')
  | (Ast.Expr.Lt, Value.V_Bool b, Value.V_Bool b') -> Value.V_Bool (b < b')
  | (Ast.Expr.Le, Value.V_Int n, Value.V_Int n') -> Value.V_Bool (n <= n')
  | (Ast.Expr.Le, Value.V_Bool b, Value.V_Bool b') -> Value.V_Bool (b <= b')
  | (Ast.Expr.Gt, Value.V_Int n, Value.V_Int n') -> Value.V_Bool (n > n')
  | (Ast.Expr.Gt, Value.V_Bool b, Value.V_Bool b') -> Value.V_Bool (b > b')
  | (Ast.Expr.Ge, Value.V_Int n, Value.V_Int n') -> Value.V_Bool (n >= n')
  | (Ast.Expr.Ge, Value.V_Bool b, Value.V_Bool b') -> Value.V_Bool (b >= b')
  | _ -> raise(TypeError "Binary operation (binop) applied to operands of the incorrect type.")

(*  unop op v = v', where v' is the result of applying the semantic
 *  denotation of `op` to `v`.
 *)
let unop (op : Ast.Expr.unop) (v : Value.t) : Value.t =
  match (op, v) with
  | (Ast.Expr.Neg, Value.V_Int n) -> Value.V_Int (-n)
  | (Ast.Expr.Not, Value.V_Bool b) -> Value.V_Bool (not b)
  | _ -> raise(TypeError "Unary operation (unop) applied to operand of the incorrect type.")



(* exec p:  Execute the program `p`.
 *)
let exec (p : Ast.Prog.t) : unit =

  match p with
  | Ast.Prog.Pgm fundefs ->
    let rho0 =
      Env.empty
      |> fun rho -> Env.declare rho "stdin" Value.V_None
      |> fun rho -> Env.declare rho "stdout" Value.V_None

    in

    let find_function (f : Ast.Id.t) : Ast.Prog.fundef =
      match List.find_opt (fun (name, _, _) -> name = f) fundefs with
      | Some fd -> fd
      | None -> raise (UndefinedFunction f)
    in

    let rec eval (rho : Env.t) (e : Ast.Expr.t) : Value.t =
      match e with
      | Ast.Expr.Num n -> Value.V_Int n
      | Ast.Expr.Bool b -> Value.V_Bool b
      | Ast.Expr.Var x -> Env.lookup rho x
      | Ast.Expr.Str s -> Value.V_Str s
      | Ast.Expr.Unop (op, e1) -> 
        let v = eval rho e1 in
          unop op v
      | Ast.Expr.Binop (op, e1, e2) ->
        let v1 = eval rho e1 in
        let v2 = eval rho e2 in
        binop op v1 v2
      
      | Ast.Expr.Call (f, args) ->
        if String.equal f "fprintf" then
          match args with
          | _file :: fmt :: rest ->
              (match eval rho fmt with
              | Value.V_Str s ->
                  let vs = List.map (eval rho) rest in
                  Io.do_fprintf s vs;
                  Value.V_None
              | _ -> raise (TypeError "fprintf format must be string"))
          | _ -> raise (TypeError "fprintf expects (file, format, ...)")

        else
          let (_, params, body) = find_function f in
          if List.length params <> List.length args then
            raise (TypeError "Wrong number of arguments");
          let arg_values = List.map (eval rho) args in
          let param_env =
            List.fold_left2
              (fun env param v -> Env.declare env param v)
              Env.empty
              params
              arg_values
          in
          let frame =
            List.fold_left
            (fun (frame : Frame.t) (stmt : Ast.Stm.t) ->
              match frame with
              | Frame.Return _ -> frame
              | Frame.Envs env -> exec_stmnt env stmt)
            (Frame.Envs param_env)
              body
          in
          match frame with
          | Frame.Return v -> v
          | Frame.Envs _ -> raise (NoReturn f)

    and exec_stmnt (rho : Env.t) (s : Ast.Stm.t) : Frame.t =
      (match s with

      | Ast.Stm.VarDec vars ->
          let env' =
            List.fold_left
              (fun env (x, init_opt) ->
                match init_opt with
                | None ->
                    Env.declare env x Value.V_Undefined
                | Some e ->
                    let v = eval env e in
                    Env.declare env x v
              )
              rho
              vars
          in
          Frame.Envs env'

      | Ast.Stm.Assign (x, e) ->
          let v = eval rho e in
          let env' = Env.assign rho x v in
          Frame.Envs env'

      | Ast.Stm.Expr e ->
          let _ = eval rho e in
          Frame.Envs rho

      | Ast.Stm.Block stms ->
          let rho' = Env.push rho in
          let rec exec_block env ss =
            match ss with
            | [] -> Frame.Envs env
            | s :: rest ->
                let frame = exec_stmnt env s in
                match frame with
                | Frame.Return _ -> frame
                | Frame.Envs env' -> exec_block env' rest
          in
          let frame = exec_block rho' stms in
          (match frame with
          | Frame.Return v ->
              Frame.Return v
          | Frame.Envs env ->
              let rho_final = Env.pop env in
              Frame.Envs rho_final)

      | Ast.Stm.IfElse (cond, s1, s2) ->
          (match eval rho cond with
          | Value.V_Bool true -> exec_stmnt rho s1
          | Value.V_Bool false -> exec_stmnt rho s2
          | _ -> raise (TypeError "Condition must be boolean"))

      | Ast.Stm.While (cond, body) ->
          let rec loop env =
            match eval env cond with
            | Value.V_Bool true ->
              let frame = exec_stmnt env body in
              (match frame with
              | Frame.Return _ -> frame
              | Frame.Envs env -> loop env)
            | Value.V_Bool false ->
                Frame.Envs env
            | _ ->
                raise (TypeError "While condition must be boolean")
          in
          loop rho

      | Ast.Stm.Return None ->
          Frame.Return Value.V_None

      | Ast.Stm.Return (Some e) ->
          let v = eval rho e in
          Frame.Return v

      | Ast.Stm.Fscanf (_, fmt, x) ->
          let v = Io.do_fscanf fmt in
          let env' = Env.assign rho x v in
          Frame.Envs env'
      )

    in 

    let _ = eval rho0 (Ast.Expr.Call ("main", [])) in
    ()


