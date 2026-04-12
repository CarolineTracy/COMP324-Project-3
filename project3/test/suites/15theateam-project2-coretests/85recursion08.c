/*!tests!
 *
 * {
 *    "input":      [],
 *    "exception":     "NoReturn"
 * }
 * 
 */

int recurs_func0 (int a, int b, int c) {
    if (a > 0) return b + 1;
    else return recurs_func0(a + 2, b + 1, c) ;
}

int recurs_func1 (int x, int y, int z) {
    int c = 5 ;
}

void main() {
    fprintf(stdout, "%d\n", recurs_func0(4, 8, 1)) ;
    fprintf(stdout, "%d\n", recurs_func1(19, 14, 3)) ;

    return ;
}