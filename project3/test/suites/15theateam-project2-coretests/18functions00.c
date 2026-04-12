/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["6"]
 * }
 *
 */

int f (int x, int y) {
    return x + y ;
}

void main() {
    int x = 4 ;
    int res = f (x, 2) ;
    fprintf(stdout, "%d\n", res) ;
    return ;
}