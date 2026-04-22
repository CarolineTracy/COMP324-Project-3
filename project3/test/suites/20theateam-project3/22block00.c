/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     []
 * }
 *
 */

void main() {
    int y ;

    // LOW → LOW
    {
        int y ;
        fprintf(stdout_lo, "%d\n", y) ;
    }

    // LOW → HIGH
    fprintf(stdout_hi, "%d\n", y) ;

    // HIGH → HIGH
    {
        int z ;
        fprintf(stdout_hi, "%d\n", z) ;
    }

    // HIGH → LOW
    {
        int z ;
        fprintf(stdout_lo, "%d\n", z) ;
    }

    return ;
}