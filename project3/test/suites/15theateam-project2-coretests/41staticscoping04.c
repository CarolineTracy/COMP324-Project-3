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
    int z = 7 ;
    int w = f (4, 5) ;
    return ;
}