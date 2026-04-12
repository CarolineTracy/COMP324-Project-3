/*!tests!
 *
 * {
 *    "input":      [],
 *    "exception":  "MultipleDeclaration"
 * }
 *
 */

int f (int x, int y) {
    int x = 17 ;
    return x + y ;
}

void main() {
    int x = 4 ;
    fprintf(stdout, "%d\n", f(1, 6)) ;
    return ;
}