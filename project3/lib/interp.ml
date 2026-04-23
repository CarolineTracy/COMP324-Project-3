(* COMP 324 Project 3:  C- interpreter with dynamic security enforcement.
 *
 * Saakshi Challa, Caroline Tracy, Siiso Daauud
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

(* Raised when public output depends on private input.
 *)
exception SecurityError

(* Raised when the no sensitive upgrade condition is violated.
 *
 * Code that fails the NSU check must raise this exception, even if
 * [SecurityError] could be raised for other reasons.
 *)
exception NSU_Error


(* Values.
 *)
module PrimValue = struct
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
(*  binop op v v' = v'', where v'' is the result of applying the semantic
 *  denotation of `op` to `v` and `v''`.
 *)
let binop (op : Ast.Expr.binop) (v : PrimValue.t) (v' : PrimValue.t) : PrimValue.t =
  match (op, v, v') with
  | (Ast.Expr.Plus, PrimValue.V_Int n, PrimValue.V_Int n') -> PrimValue.V_Int (n + n')
  | (Ast.Expr.Minus, PrimValue.V_Int n, PrimValue.V_Int n') -> PrimValue.V_Int (n - n')
  | (Ast.Expr.Times, PrimValue.V_Int n, PrimValue.V_Int n') -> PrimValue.V_Int (n * n')
  | (Ast.Expr.Div, PrimValue.V_Int n, PrimValue.V_Int n') -> PrimValue.V_Int (n / n')
  | (Ast.Expr.Mod, PrimValue.V_Int n, PrimValue.V_Int n') -> PrimValue.V_Int (n mod n')
  | (Ast.Expr.And, PrimValue.V_Bool b, PrimValue.V_Bool b') -> PrimValue.V_Bool (b && b')
  | (Ast.Expr.Or, PrimValue.V_Bool b, PrimValue.V_Bool b') -> PrimValue.V_Bool (b || b')
  | (Ast.Expr.Eq, PrimValue.V_Int n, PrimValue.V_Int n') -> PrimValue.V_Bool (n = n')
  | (Ast.Expr.Eq, PrimValue.V_Bool b, PrimValue.V_Bool b') -> PrimValue.V_Bool (b = b')
  | (Ast.Expr.Ne, PrimValue.V_Int n, PrimValue.V_Int n') -> PrimValue.V_Bool (n != n')
  | (Ast.Expr.Ne, PrimValue.V_Bool b, PrimValue.V_Bool b') -> PrimValue.V_Bool (b != b')
  | (Ast.Expr.Lt, PrimValue.V_Int n, PrimValue.V_Int n') -> PrimValue.V_Bool (n < n')
  | (Ast.Expr.Lt, PrimValue.V_Bool b, PrimValue.V_Bool b') -> PrimValue.V_Bool (b < b')
  | (Ast.Expr.Le, PrimValue.V_Int n, PrimValue.V_Int n') -> PrimValue.V_Bool (n <= n')
  | (Ast.Expr.Le, PrimValue.V_Bool b, PrimValue.V_Bool b') -> PrimValue.V_Bool (b <= b')
  | (Ast.Expr.Gt, PrimValue.V_Int n, PrimValue.V_Int n') -> PrimValue.V_Bool (n > n')
  | (Ast.Expr.Gt, PrimValue.V_Bool b, PrimValue.V_Bool b') -> PrimValue.V_Bool (b > b')
  | (Ast.Expr.Ge, PrimValue.V_Int n, PrimValue.V_Int n') -> PrimValue.V_Bool (n >= n')
  | (Ast.Expr.Ge, PrimValue.V_Bool b, PrimValue.V_Bool b') -> PrimValue.V_Bool (b >= b')
  | _ -> raise(TypeError "Binary operation (binop) applied to operands of the incorrect type.")

(*  unop op v = v', where v' is the result of applying the semantic
 *  denotation of `op` to `v`.
 *)
let unop (op : Ast.Expr.unop) (v : PrimValue.t) : PrimValue.t =
  match (op, v) with
  | (Ast.Expr.Neg, PrimValue.V_Int n) -> PrimValue.V_Int (-n)
  | (Ast.Expr.Not, PrimValue.V_Bool b) -> PrimValue.V_Bool (not b)
  | _ -> raise(TypeError "Unary operation (unop) applied to operand of the incorrect type.")



(* Security labels.
 *
 * This module defines the two-point security lattice Low <= High.  However,
 * clients must treat the security labels abstractly in the sense that they
 * may only use the values specified in the given signature.  Notice that
 * those values:
 * - Define the type of security labels, but not the definition of that type;
 * - Define bottom, leq, and join, which taken together should make the type
 *   of security labels into a join semi-lattice.
 * - Define some convenience functions for printing and equality checking.
 * - Define [of_channel], which returns the security level associated to a
 *   given input or output channel by name.
 *
 * For this particular security lattice, `bottom` = `Low` and security labels
 * are associated to I/O channels as follows:
 *
 * stdout_lo, stdin_lo --> Low
 * stdout_hi, stdin_hi --> High
 *)
module SecLab : sig
  (** The type of a security label.
   *)
  type t

  (** The bottom security label.  It must be that [leq bottom x] = [true] for
   *  all x.
   *)
  val bottom : t

  (** A partial order on security labels.
   *)
  val leq : t -> t -> bool

  (** Equality predicate for security labels.  It must be that
   * [eq x y] = [leq x y && leq y x].
   *)
  val eq : t -> t -> bool

  (** [join x y] is the least upper bound of [x] and [y] with respect to
   * [leq].
   *)
  val join : t -> t -> t

  (** [to_string x] = a string representation of [x].
   *)
  val to_string : t -> string

  (** [pp] is a formatter for [t].
   *)
  val pp : Format.formatter -> t -> unit

  (** [of_channel ch] = the security level associated to the channel [ch].
   *)
  val of_channel : Ast.Id.t -> t
end = struct

  type t = Low | High
  [@@deriving show]

  let bottom = Low

  (* to_string x = a string representation of x.
   *)
  let to_string (x : t) : string =
    match x with
    | Low -> "L"
    | High -> "H"

  (* eq x y = true,  if x and y are the same security label
   *          false, otherwise.
   *)
  let eq (x: t) (y : t) : bool =
    match (x, y) with 
    | (Low, Low) -> true
    | (High, High) -> true
    | (Low, High) -> false 
    | (High, Low) -> false

  (* leq x y = true,  eq x y or x = Low and y = High
   *           false, o/w.
   *)
  let leq (x : t) (y : t) : bool =
    match (x, y) with 
    | (Low, Low) -> true 
    | (High, High) -> true 
    | (Low, High) -> true 
    | (High, Low) -> false 

  (* join x y = the maximum of x and y with respect to `leq`.
   *)
  let join (x : t) (y : t) : t =
    match (x, y) with 
    | (Low, Low) -> Low 
    | (Low, High) -> High 
    | (High, Low) -> High 
    | (High, High) -> High 
    

  (* [of_channel ch] = the security label associated to the channel [ch].
   *)
  let of_channel (ch : Ast.Id.t) : t =
    match ch with
    | ("stdout" | "stdin") -> Low
    | ("stdout_lo" | "stdin_lo") -> Low
    | ("stdout_hi" | "stdin_hi") -> High
    | _ -> invalid_arg ch

end


(* Module for environments. We will use ρ as a metavariable over environments.
 *)
module Env = struct

  type env = (Ast.Id.t * (PrimValue.t * SecLab.t)) list
  type t = env list

  let empty : t = [[]]

  let from_list (rho : t) : t = rho

  let push (rho : t) : t =
    [] :: rho

  let pop (rho : t) : t =
    match rho with
    | [] -> failwith "pop on empty environment stack"
    | _ :: rest -> rest

  let rec lookup (rho : t) (x : Ast.Id.t) : PrimValue.t * SecLab.t =
    match rho with
    | [] -> raise (UnboundVariable x)
    | scope :: rest ->
        match List.assoc_opt x scope with
        | Some v -> v
        | None -> lookup rest x

  let declare (rho : t) (x : Ast.Id.t) (v : PrimValue.t * SecLab.t) : t =
    match rho with
    | [] -> failwith "declare on empty environment stack"
    | scope :: rest ->
        if List.mem_assoc x scope then
          raise (MultipleDeclaration x)
        else
          ((x, v) :: scope) :: rest

  let rec assign (rho : t) (x : Ast.Id.t) (v : PrimValue.t * SecLab.t) : t =
    match rho with
    | [] -> raise (UnboundVariable x)
    | scope :: rest ->
        if List.mem_assoc x scope then
          ((x, v) :: List.remove_assoc x scope) :: rest
        else
          scope :: assign rest x v

end

(* Added security label to the return value*)
module Frame = struct
  type t =
    | Envs of Env.t
    | Return of PrimValue.t * SecLab.t
end

(* Module for input/output built-in functions.
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

  (* The input channel.  Default is standard input.
   *)
  let in_channel : Scanf.Scanning.in_channel ref =
    ref Scanf.Scanning.stdin

  (* The output function.  Default is to print the string to standard output
   * and flush.
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
  let do_fprintf (fmt : string) (vs : PrimValue.t list) : unit =
    let rec build_result (fmt : string) (vs : PrimValue.t list) : string =
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
        | (_, []) ->
          raise @@ TypeError "Too few values to print for format string"
        | ("%d", V_Int n :: vs') -> 
          Printf.sprintf
            "%d%s"
            n
            (build_result (tailtail fmt) vs')
        | ("%b", V_Bool b :: vs') -> 
          Printf.sprintf
            "%b%s"
            b
            (build_result (tailtail fmt) vs')
        | ("%s", V_Str s :: vs') -> 
          Printf.sprintf
            "%s%s"
            s
            (build_result (tailtail fmt) vs')
        | _ ->
          raise @@ TypeError "Bad % specifier or incorrect value type"
    in

    !output (build_result fmt vs)

  (* do_fscanf fmt = v, where v is the value read from stdin according to fmt.
   *)
  let do_fscanf (fmt : string) : PrimValue.t =
    let fmt' : string = String.trim fmt in
    match fmt' with
    | "%d" -> V_Int (Scanf.bscanf !in_channel " %d" (fun n -> n))
    | "%b" -> V_Bool (Scanf.bscanf !in_channel " %b" (fun b -> b))
    | "%s" -> V_Str (Scanf.bscanf !in_channel " %s" (fun s -> s))
    | _ ->
      raise @@ TypeError (
        Printf.sprintf
        "Bad scanf format string: %s"
        fmt
      )

end




(* exec p:  Execute the program `p`.
 *)
let exec (p : Ast.Prog.t) : unit =

  match p with
  | Ast.Prog.Pgm fundefs ->
    let rho0 =
      Env.empty
      |> fun rho -> Env.declare rho "stdin" (PrimValue.V_None, SecLab.bottom) 
      |> fun rho -> Env.declare rho "stdout" (PrimValue.V_None, SecLab.bottom) 
      |> fun rho -> Env.declare rho "stdin_hi" (PrimValue.V_None, SecLab.bottom) 
      |> fun rho -> Env.declare rho "stdin_lo" (PrimValue.V_None, SecLab.bottom)
      |> fun rho -> Env.declare rho "stdout_lo" (PrimValue.V_None, SecLab.bottom) 
      |> fun rho -> Env.declare rho "stdout_hi" (PrimValue.V_None, SecLab.bottom) 

    in

    let find_function (f : Ast.Id.t) : Ast.Prog.fundef =
      match List.find_opt (fun (name, _, _) -> name = f) fundefs with
      | Some fd -> fd
      | None -> raise (UndefinedFunction f)
    in

    let rec eval (rho : Env.t) (e : Ast.Expr.t) : PrimValue.t * SecLab.t =
      match e with
      | Ast.Expr.Num n -> (PrimValue.V_Int n , SecLab.bottom) 
      | Ast.Expr.Bool b -> (PrimValue.V_Bool b , SecLab.bottom) 
      | Ast.Expr.Var x -> Env.lookup rho x
      | Ast.Expr.Str s -> (PrimValue.V_Str s , SecLab.bottom) 
      | Ast.Expr.Unop (op, e1) -> 
        let (v , label) = eval rho e1 in
          (unop op v , label)
      | Ast.Expr.Binop (op, e1, e2) ->
        let (v1 , label1) = eval rho e1 in
        let (v2 , label2) = eval rho e2 in
        (binop op v1 v2 , SecLab.join label1 label2)
      
      | Ast.Expr.Call (f, args) ->
        if String.equal f "fprintf" then
          match args with
          | _file :: fmt :: rest ->
              (*get channel name from the file argument*)
              let ch = (match _file with 
                | Ast.Expr.Var ch -> ch
                | _ -> raise (TypeError "fprintf first arg must be a channel")) in 
              (* get the security label of the output channel *)
              let ch_label = SecLab.of_channel ch in 
              (match eval rho fmt with
              |  (PrimValue.V_Str s, _) -> (* accounts for the tuple return with a security label*)
                  let vs = List.map (eval rho) rest in
                  (* check that no value is more secret than the channel allows *)
                  List.iter (fun (_, lbl) -> 
                    if not (SecLab.leq lbl ch_label) then 
                      raise SecurityError) vs; 
                  (* strip labels before passing to do fprintf *)
                  let vs1 = List.map (fun (v, _) -> v) vs in 
                  Io.do_fprintf s vs1;
                  (* return None with a public label *)
                  (PrimValue.V_None, SecLab.bottom) 
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
          | Frame.Return (v, lbl) -> (v, lbl) 
          | Frame.Envs _ -> raise (NoReturn f)

    and exec_stmnt (rho : Env.t) (s : Ast.Stm.t) : Frame.t =
      (match s with

      | Ast.Stm.VarDec vars ->
          let env' =
            List.fold_left
              (fun env (x, init_opt) ->
                match init_opt with
                | None ->
                    Env.declare env x (PrimValue.V_Undefined, SecLab.bottom) 
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
          | Frame.Return (v, lbl) ->
              Frame.Return (v, lbl)
          | Frame.Envs env ->
              let rho_final = Env.pop env in
              Frame.Envs rho_final)

      | Ast.Stm.IfElse (cond, s1, s2) ->
        (match eval rho cond with
          (* if condition is true, check NSU before executing true branch  *)
          | (PrimValue.V_Bool true , lbl)   -> 
            (* if condition came from a secret channel, raise NSU error  *)
            (if not (SecLab.leq lbl SecLab.bottom) then raise NSU_Error;
             exec_stmnt rho (match s1 with Ast.Stm.Block _ -> s1 | _ -> Ast.Stm.Block [s1]))
            (* if condition is false, check NSU before executing false branch *)
          | (PrimValue.V_Bool false , lbl) -> 
            (*if condition came from a secret channel, raise NSU error *)
            (if not (SecLab.leq lbl SecLab.bottom) then raise NSU_Error;
             exec_stmnt rho (match s2 with Ast.Stm.Block _ -> s2 | _ -> Ast.Stm.Block [s2]))
          | _ -> raise (TypeError "Condition must be boolean"))

        | Ast.Stm.While (cond, body) ->
          (match body with
          | Ast.Stm.Block _ ->
              let rec loop env =
                match eval env cond with
                | (PrimValue.V_Bool true, lbl) ->
                  if not (SecLab.leq lbl SecLab.bottom) then raise NSU_Error; 
                  let frame = exec_stmnt env body in
                  (match frame with
                  | Frame.Return _ -> frame
                  | Frame.Envs env1 -> loop env1)
                | (PrimValue.V_Bool false, lbl) ->
                    if not (SecLab.leq lbl SecLab.bottom) then raise NSU_Error; 
                    Frame.Envs env
                | _ ->
                    raise (TypeError "While condition must be boolean")
              in
              loop rho
          | _ ->
              raise (TypeError "While body must be a block"))

      | Ast.Stm.Return None ->
          Frame.Return (PrimValue.V_None, SecLab.bottom) 

      | Ast.Stm.Return (Some e) ->
          let (v, lbl) = eval rho e in
          Frame.Return (v, lbl)

      | Ast.Stm.Fscanf (file, fmt, x) ->
          let v = Io.do_fscanf fmt in
          (* tag the value with the security label of the input channel *)
          let lbl = SecLab.of_channel file in 
          let env' = Env.assign rho x (v, lbl) in
          Frame.Envs env'
      )

    in 

    let _ = eval rho0 (Ast.Expr.Call ("main", [])) in
    ()


