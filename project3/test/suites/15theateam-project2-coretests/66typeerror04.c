/*!tests!
 *
 * {
 *    "input":      [],
 *    "exception":     "TypeError"
 * }
 * 
 */

int f (int a, int b) {
    return a * b ;
}

void main() {
    int c = f(1, 5, 6) ;
    return ;
}