/*!tests!
 *
 * {
 *    "input":      ["2", "-5", "4", "3"],
 *    "exception":  "SecurityException"
 * }
 * 
 * {
 *    "input":      ["10", "1", "-2", "6"],
 *    "exception":  "SecurityException"
 * }
 *
 */



void main() {
    int a, b, c, d, e = 8, f = -10;

    fscanf(stdin_hi, "%d", &a) ;
    fscanf(stdin_hi, "%d", &b) ;
    fscanf(stdin_hi, "%d", &c) ;
    fscanf(stdin_hi, "%d", &d) ;

    a = a + 4 ;
    fprintf(stdout_lo, "%d\n", a) ;
    fprintf(stdout_lo, "%d\n", -a) ;

    b = 4 - -b ;
    fprintf(stdout_lo, "%d\n", b) ;

    fprintf(stdout_lo, "%d\n", c * 8) ;

    d = d * 0;
    fprintf(stdout_lo, "%d\n", d) ;

    fprintf(stdout_lo, "%d\n", e / 4) ;
    fprintf(stdout_lo, "%d\n", e % 3) ;

    fprintf(stdout_lo, "%d\n", f - 2) ;

    return ;
}