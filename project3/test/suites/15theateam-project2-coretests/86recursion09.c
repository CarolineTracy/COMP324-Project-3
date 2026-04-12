/*!tests!
 *
 * {
 *    "input":      [],
 *    "exception":     "MultipleDeclaration"
 * }
 * 
 */

int recurs_func0 (int a, int b, int c) {
    int c = 0 ;
    if (a > 0) return b + 1;
    else return recurs_func0(a + 2, b + 1, c) ;
}

int recurs_func1 (int x, int y, int z) {
    if (x == 4) return x + y + z;
    else return recurs_func1(x + 1, y - 1, z * 1) ;
}

void main() {
    fprintf(stdout, "%d\n", recurs_func0(4, 8, 1)) ;
    fprintf(stdout, "%d\n", recurs_func1(19, 14, 3)) ;

    return ;
}