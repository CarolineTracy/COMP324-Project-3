/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["20"]
 * }
 *
 */

void main() {
    int x = 20 ;

    // LOW --> LOW
    fprintf(stdout_lo, "%d\n", x) ;

    // LOW --> HIGH
    fprintf(stdout_hi, "%d\n", x) ;

    // HIGH --> HIGH
    int y = 30 ;
    fprintf(stdout_hi, "%d\n", y) ;

    // HIGH --> LOW
    fprintf(stdout_lo, "%d\n", y) ;

    return ;
}