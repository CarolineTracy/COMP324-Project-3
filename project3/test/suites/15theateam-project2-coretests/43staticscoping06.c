/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["-1"]
 * }
 *
 */

int g (int a, int b) {
    return a - b ;
}

void main() {
    fprintf(stdout, "%d\n", g(2,3)) ;
    int a = 19 ;
    return ;
}