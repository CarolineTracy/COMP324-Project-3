/*!tests!
 *
 * {
 *    "input":      ["0", "3", "-2", "4", "1", "5", "1"],
 *    "output":     ["21", "6"]
 * }
 * 
 */

int recurs_func0 (int a, int b, int c) {
    fscanf(stdin, "%d", &a) ;
    if (a > 0) return b + 1;
    else return recurs_func0(a + 2, b + 1, c) ;
}

int recurs_func1 (int x, int y, int z) {
    fscanf(stdin, "%d", &x) ;
    if (x > 4) return x + y + z;
    else return recurs_func1(x + 1, y - 1, z * 1) ;
}

void main() {
    fprintf(stdout, "%d\n", recurs_func1(-6, 17, 4)) ;
    fprintf(stdout, "%d\n", recurs_func0(-8, 5, 6)) ;

    return ;
}
