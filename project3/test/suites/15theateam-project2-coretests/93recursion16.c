/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["170"]
 * }
 * 
 */

int recurs_func0 (int a, int b, int c) {
    if (a > 0) return b + 1;
    else return recurs_func0(a + 2, b + 1, c) ;
}

int recurs_func1 (int x, int y, int z) {
    int j = 6 ;
    if (z > 100) return z + x;
    while (x > 4) {
        j = j + 1;
        x = x - 1;
    }
    return recurs_func1(10, y-1, z * 2) ;
}

void main() {
    fprintf(stdout, "%d\n", recurs_func1(10, 4, 10)) ;

    return ;
}