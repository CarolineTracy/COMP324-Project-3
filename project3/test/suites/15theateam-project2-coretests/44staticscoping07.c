/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["5", "2"]
 * }
 *
 */

int f (int x, int y) {
    return x + y ;
}

void main() {
    int x = 2 ;
    fprintf(stdout, "%d\n", f(0, 5)) ;
    fprintf(stdout, "%d\n", x) ;
    return ;
}