/*!tests!
 *
 * {
 *    "input":      [],
 *    "exception":     "UnboundVariable"
 * }
 * 
 */

void main() {
    int a = 9 ;

    // LOW → LOW
    fprintf(stdout_lo, "%d\n", a) ;

    // LOW → LOW
    fprintf(stdout_lo, "%d\n", a) ;

    // LOW → LOW
    fprintf(stdout_lo, "%d\n", a - 10) ;

    // LOW → LOW
    fprintf(stdout_lo, "%d\n", a * 18) ;

    // LOW → LOW
    fprintf(stdout_lo, "%d\n", a + 4) ;

    // LOW → LOW
    fprintf(stdout_lo, "%d\n", a) ;

    // LOW → LOW
    fprintf(stdout_lo, "%d\n", a) ;

    // LOW → LOW
    fprintf(stdout_lo, "%d\n", w) ;

    return ;
}