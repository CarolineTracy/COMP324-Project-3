/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["-144", "-162", "-66"]
 * }
 *
 */


void main() {
    int t = 8, u = 1, v = 4, w = 6, x = 18, y = -9, z = -22 ;

    fprintf(stdout, "%d\n", t - -u + z * w + z + x / x % z) ;

    fprintf(stdout, "%d\n", x / u % z + w - z * y + t - -v) ;

    fprintf(stdout, "%d\n", v * x + z - u - x * w + y % z + u * t / v) ;

    return ;
}