/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["4", "4", "18", "18", "0", "0", "11", "11", "66"]
 * }
 *
 */

void main() {
    int y ;
    y = 4 ;

    // LOW → LOW
    fprintf(stdout_lo, "%d\n", y) ;

    {
        fprintf(stdout_lo, "%d\n", y) ;
        y = 18 ;

        // LOW → HIGH
        fprintf(stdout_hi, "%d\n", y) ;

        {
            // HIGH → HIGH
            fprintf(stdout_hi, "%d\n", y) ;
            y = 0 ;

            // HIGH → LOW
            fprintf(stdout_lo, "%d\n", y) ;
        }

        fprintf(stdout_lo, "%d\n", y) ;
        y = 11 ;

        // LOW → HIGH
        fprintf(stdout_hi, "%d\n", y) ;
    }

    // HIGH → HIGH
    fprintf(stdout_hi, "%d\n", y) ;

    y = 66 ;

    // HIGH → LOW
    fprintf(stdout_lo, "%d\n", y) ;

    return ;
}