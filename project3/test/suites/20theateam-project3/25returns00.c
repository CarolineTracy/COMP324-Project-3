/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["9"]
 * }
 *
 */

int f (int x, int y) {
    int z = x + y ;
    return z ;
    z = z + 12 ;
    return z ;
}

void main() {
    int res = f(5, 4) ;

    // LOW → LOW
    fprintf(stdout_lo, "%d\n", res) ;

    // LOW → HIGH
    fprintf(stdout_hi, "%d\n", res) ;

    // HIGH → HIGH
    int h = f(res, 1) ;
    fprintf(stdout_hi, "%d\n", h) ;

    // HIGH → LOW
    fprintf(stdout_lo, "%d\n", h) ;

    return ;
}