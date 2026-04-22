/*!tests!
 *
 * {
 *    "input":      ["6", "-3", "5", "2"],
 *    "output":     ["10", "-10", "1", "40", "0", "2", "2", "-12"]
 * }
 * 
 * {
 *    "input":      ["-4", "8", "-1", "9"],
 *    "output":     ["0", "0", "12", "-8", "0", "2", "2", "-12"]
 * }
 *
 */



void main() {
    int a, b, c, d, e = 8, f = -10;

    fscanf(stdin_lo, "%d", &a) ;
    fscanf(stdin_lo, "%d", &b) ;
    fscanf(stdin_lo, "%d", &c) ;
    fscanf(stdin_lo, "%d", &d) ;

    a = a + 4 ;
    fprintf(stdout_hi, "%d\n", a) ;
    fprintf(stdout_hi, "%d\n", -a) ;

    b = 4 - -b ;
    fprintf(stdout_hi, "%d\n", b) ;

    fprintf(stdout_hi, "%d\n", c * 8) ;

    d = d * 0;
    fprintf(stdout_hi, "%d\n", d) ;

    fprintf(stdout_hi, "%d\n", e / 4) ;
    fprintf(stdout_hi, "%d\n", e % 3) ;

    fprintf(stdout_hi, "%d\n", f - 2) ;

    return ;
}