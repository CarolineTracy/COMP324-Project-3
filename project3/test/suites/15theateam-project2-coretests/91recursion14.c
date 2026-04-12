/*!tests!
 *
 * {
 *    "input":      [],
 *    "exception":     "TypeError"
 * }
 * 
 */

int recurs_func0 (int a, int b, int c) {
    if (a > 0) return b / 0;
    else return recurs_func0(a + 1, b + 1, c, c) ;
}

int recurs_func1 (int x, int y, int z) {
    if (x == 4) return x / 0;
    else return recurs_func1(x + 1 + "yes", y - 1, z * 1) ;
}

void main() {
    fprintf(stdout, "%d\n", recurs_func0(-4, 8, 1)) ;
    fprintf(stdout, "%d\n", recurs_func1(19, 14, 3)) ;

    return ;
}