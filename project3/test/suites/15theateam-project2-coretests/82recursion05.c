/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["16"]
 * }
 * 
 */

int f (int a, int b) {
    int c = 4 ;
    return a + c ;
}

int g (bool w) {
    if (w) return 8 ;
    else return 19 ;
}

char* h (int r, int o, char* ui) {
    while (r > 0) {
        r = r - 1;
        o = o + 1 ;
    }
    return ui ;
}

int func1 (int x, int y) {
    return x + y + z ;
}

int recurs_func (int a, int b, char* j) {
    if (a > 0) return b + 1;
    else return recurs_func(a + 2, b + 1, j) ;
}

int non_recurs_func (int a, int b, char* j) {
    if (a > 0) return b + 1;
    else return b * 2 ;
}

void main() {
    fprintf(stdout, "%d\n", non_recurs_func(f(-28, 9), g(true), h(4, 7, "lol"))) ;

    return ;
}