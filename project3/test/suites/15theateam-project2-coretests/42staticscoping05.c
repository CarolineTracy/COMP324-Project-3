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
    int a = 19 ;
    fprintf(stdout, "%d\n", g(2,3)) ;
    return ;
}