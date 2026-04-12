/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["16"]
 * }
 *
 */

int f (int q, int y) {
    int x = 10 ;
    return x + y ;
}

void main() {
    int x = 4 ;
    fprintf(stdout, "%d\n", f(1, 6)) ;
    return ;
}