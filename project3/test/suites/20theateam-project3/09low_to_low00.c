/*!tests!
 *
 * {
 *    "input":      ["3", "7", "-1", "0"],
 *    "output":     ["7", "-7", "11", "-8", "0", "2", "2", "-12"]
 * }
 * 
 * {
 *    "input":      ["-19", "0", "11", "-120"],
 *    "output":     ["-15", "15", "4", "88", "0", "2", "2", "-12"]
 * }
 *
 * {
 *    "input":      ["3", "7", "-1", "0"],
 *    "exception":  "SecurityException"
 * }
 *
 * {
 *    "input":      ["3", "7", "-1", "0"],
 *    "output":     ["7", "-7", "11", "-8", "0", "2", "2", "-12"]
 * }
 *
 */



void main() {
    int a, b, c, d, e = 8, f = -10;

    // ---- INPUTS ----
    fscanf(stdin_lo, "%d", &a) ;
    fscanf(stdin_lo, "%d", &b) ;
    fscanf(stdin_lo, "%d", &c) ;
    fscanf(stdin_lo, "%d", &d) ;

    // ---- BINARY OPERATIONS ----

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