/*!tests!
 *
 * {
 *    "input":      [],
 *    "exception":     "UnboundVariable"
 * }
 *
 */

int f (int x, int y) {
    return x + y + z ;
}

void main() {
    int x = 4 ;
    fprintf(stdout, "%d\n", f(x, 0)) ;
    return ;
}