/*!tests!
 *
 * {
 *    "input":      ["one two three four 5 6"],
 *    "output":     ["one", "two", "three", "four", "5", "6"]
 * }
 * 
 */

void main() {
    char* a, b, c, d ;
    int e, f ;

    fscanf(stdin_lo, "%s", &a) ;

    fscanf(stdin_lo, "%s", &b) ;

    fscanf(stdin_hi, "%s", &c) ;

    fscanf(stdin_hi, "%s", &d) ;

    fscanf(stdin_lo, "%d", &e) ;

    fscanf(stdin_hi, "%d", &f) ;

    fprintf(stdout_lo, "%s\n", a) ;
    fprintf(stdout_lo, "%s\n", b) ;
    fprintf(stdout_lo, "%s\n", c) ;
    fprintf(stdout_lo, "%s\n", d) ;
    fprintf(stdout_lo, "%d\n", e) ;
    fprintf(stdout_lo, "%d\n", f) ;

    return ;
}