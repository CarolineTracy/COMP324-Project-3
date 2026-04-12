/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["12", "8", "13", "17", "false", "true", "new jeans", "hi siiso lol"]
 * }
 * 
 */

int recurs_func0 (int a, int b, char* j) {
    if (a > 0) return b + 1;
    else return recurs_func0(a + 2, b + 1, j) ;
}

int recurs_func1 (int x, int y, int z) {
    if (x == 4) return x + y + z;
    else return recurs_func1(x + 1, y - 1, z * 1) ;
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
    fprintf(stdout, "%d\n", recurs_func0(10, 11, "katseye")) ;
    fprintf(stdout, "%d\n", recurs_func0(-6, 3, "girlset")) ;
    fprintf(stdout, "%d\n", recurs_func1(4, 8, 1)) ;
    fprintf(stdout, "%d\n", recurs_func1(0, 14, 3)) ;
    fprintf(stdout, "%b\n", recurs_func2(true, false)) ;
    fprintf(stdout, "%b\n", recurs_func2(false, true)) ;
    fprintf(stdout, "%s\n", recurs_func3(10, 8, "new jeans")) ;
    fprintf(stdout, "%s\n", recurs_func3(3, 100, "hi siiso lol")) ;

    return ;
}