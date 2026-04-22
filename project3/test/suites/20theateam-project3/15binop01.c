/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["-144", "-162", "-66"]
 * }
 *
 */

void main() {
    // LOW variables
    int t = 8, u = 1, v = 4 ;

    // HIGH variables
    int w = 6, x = 18, y = -9, z = -22 ;

    // ------------------------
    // LOW --> LOW
    int a = t - -u + v * t ;
    fprintf(stdout_lo, "%d\n", a) ;

    // ------------------------
    // LOW --> HIGH
    int b = t + u + v ;
    fprintf(stdout_hi, "%d\n", b) ;

    // ------------------------
    // HIGH --> HIGH
    int c = z * w + z + x / x % z ;
    fprintf(stdout_hi, "%d\n", c) ;

    // ------------------------
    // HIGH --> LOW
    int d = x / u % z + w - z * y + t - -v ;
    fprintf(stdout_lo, "%d\n", d) ;

    // ------------------------
    // HIGH --> LOW
    int e = v * x + z - u - x * w + y % z + u * t / v ;
    fprintf(stdout_lo, "%d\n", e) ;

    return ;
}