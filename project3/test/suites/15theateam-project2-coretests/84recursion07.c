/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["3", "8"]
 * }
 * 
 */

int recurs_func0 (int a, int b, int c) {
    if (a > 0) return b + 1;
    else return recurs_func1(a + 1, b - 1, c * 2) ;
}

int recurs_func1 (int x, int y, int z) {
    if (x > 4) return x + y + z;
    else return recurs_func0(x + 2, y + 1, z) ;
}

bool recurs_func2 (bool b, bool b0) {
    if (b) return b0;
    else return recurs_func2(!b, (b0 && b0) || b) ;
}

char* recurs_func3 (int x, int y, char* c) {
    if (x > 7) return c;
    else return recurs_func3(x + 1, y - 10, c) ;
}

void main() {
    fprintf(stdout, "%d\n", recurs_func0(-2, 2, 4)) ;
    fprintf(stdout, "%d\n", recurs_func1(-4, 6, 7)) ;

    return ;
}