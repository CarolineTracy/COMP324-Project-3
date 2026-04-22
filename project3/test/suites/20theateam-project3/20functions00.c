/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["6"]
 * }
 *
 */

int f (int x, int y) {
    return x + y ;
}

void main() {
    int x = 4 ;

    int res = f(x, 2) ;

    // LOW --> LOW
    fprintf(stdout_lo, "%d\n", res) ;

    // LOW --> HIGH
    fprintf(stdout_hi, "%d\n", res) ;

    // HIGH --> HIGH
    int h = f(res, 1) ;
    fprintf(stdout_hi, "%d\n", h) ;

    // HIGH --> LOW
    fprintf(stdout_lo, "%d\n", h) ;

    return ;
}