/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["-8"]
 * }
 *
 */

int f (int x, int y) {
    return x - y ;
}

void main() {
    int x = 10 ;
    int res0 = f (x, 2 + 6) ;
    int res1 = f (18, x + res0) ;
    int final = f (f (res0, res1), 4) ;
    fprintf(stdout, "%d\n", final) ;
    return ;
}