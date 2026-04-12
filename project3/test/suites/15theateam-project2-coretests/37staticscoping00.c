/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["7"]
 * }
 *
 */

int f (int x, int y) {
    return x + y ;
}

void main() {
    int x = 4 ;
    fprintf(stdout, "%d\n", f(1, 6)) ;
    return ;
}