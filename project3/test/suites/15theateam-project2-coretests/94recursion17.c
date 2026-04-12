/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["-2", "0", "2", "11", "19", "22"]
 * }
 * 
 */

int recurs_func0 (int a, int b, int c) {
    fprintf(stdout, "%d\n", a) ;
    if (a > 0) return b + 1;
    else return recurs_func0(a + 2, b + 1, c) ;
}

int recurs_func1 (int x, int y, int z) {
    fprintf(stdout, "%d\n", x) ;
    if (x > 4) return x + y + z;
    else return recurs_func1(x + 1, y - 1, z * 1) ;
}

void main() {
    fprintf(stdout, "%d\n", recurs_func0(-2, 8, 1)) ;
    fprintf(stdout, "%d\n", recurs_func1(19, 0, 3)) ;

    return ;
}
