/*!tests!
 *
 * {
 *    "input":      ["hi\thello\they\thaha\t8\t18"],
 *    "output":     ["hi", "hello", "hey", "haha", "8", "18"]
 * }
 * 
 * {
 *    "input":      ["yes \t no \t lol\tyes\t99 \t 0100"],
 *    "output":     ["yes", "no", "lol", "yes", "99", "100"]
 * }
 * 
 */

void main() {
    char* a, b, c, d ;
    int e, f ;

    fscanf(stdin, "%s", &a) ;
    fscanf(stdin, "%s", &b) ;
    fscanf(stdin, "%s", &c) ;
    fscanf(stdin, "%s", &d) ;
    fscanf(stdin, "%d", &e) ;
    fscanf(stdin, "%d", &f) ;

    fprintf(stdout, "%s\n", a) ;
    fprintf(stdout, "%s\n", b) ;
    fprintf(stdout, "%s\n", c) ;
    fprintf(stdout, "%s\n", d) ;
    fprintf(stdout, "%d\n", e) ;
    fprintf(stdout, "%d\n", f) ;

    return ;
}