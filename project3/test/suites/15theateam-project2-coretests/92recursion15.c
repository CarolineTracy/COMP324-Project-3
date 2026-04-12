/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["0", "7"]
 * }
 * 
 */

int recurs_func0 (int a, int b, int c) {
    if (a > 0) return b + 1;
    else return recurs_func0(a + 2, b + 1, c) ;
}

int recurs_func1 (int x, int y, int z) {
    int j = 6 ;
    while (x > 4) {
        if (y > 0) return recurs_func1(x-1, y-1, z * 2) ;
        j = j + 1;
        x = x - 1;
    }
    return y ;
}

void main() {
    fprintf(stdout, "%d\n", recurs_func1(7, 2, 3)) ;
    fprintf(stdout, "%d\n", recurs_func1(5, 8, 10)) ;

    return ;
}