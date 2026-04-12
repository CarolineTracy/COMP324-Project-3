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
    fprintf(stdout, "%d\n", f(5, 4)) ;
    return ;
}