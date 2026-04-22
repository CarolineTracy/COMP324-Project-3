/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["-1"]
 * }
 *
 */

int g (int a, int b) {
    return a - b ;
}

void main() {
    int res = g(2, 3) ;

    // LOW → LOW
    fprintf(stdout_lo, "%d\n", res) ;

    // LOW → HIGH
    fprintf(stdout_hi, "%d\n", res) ;

    // HIGH → HIGH
    int h = g(res, 1) ;
    fprintf(stdout_hi, "%d\n", h) ;

    // HIGH → LOW
    fprintf(stdout_lo, "%d\n", h) ;

    int a = 19 ;
    return ;
}