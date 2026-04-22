/*!tests!
 *
 * {
 *    "input":      ["2", "-5", "4", "3"],
 *    "output":     ["6", "-6", "-1", "32", "0", "2", "2", "-12"]
 * }
 * 
 * {
 *    "input":      ["10", "1", "-2", "6"],
 *    "output":     ["14", "-14", "5", "-16", "0", "2", "2", "-12"]
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