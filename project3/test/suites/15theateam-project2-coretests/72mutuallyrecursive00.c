/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["5", "0", "0", "5", "0"]
 * }
 * 
 */

int f (int a, int b) {
    if (a > 0) fprintf(stdout, "%d\n", g(a-1, b-1)) ;
    if (a > 0) return 0 ;
    return 5 ;
}

int g (int c, int d) {
    if (c > 0) fprintf(stdout, "%d\n", f(c-1, d-1)) ;
    if (c > 0) return 0 ;
    return 5 ;
}

void main() {
    int a = f(2, 3) ;
    fprintf(stdout, "%d\n", a) ;
    int b = g(1, 4) ;
    fprintf(stdout, "%d\n", b) ;
    return ;
}