/*!tests!
 *
 * {
 *    "input":      [],
 *    "exception":     "NoReturn"
 * }
 *
 */

int f (int a, int b) {
    int c = a * b ;
}

bool b (bool b0, int v) {
    bool b1 = !b0 ;
    if (v >= 5) return b1 ;
    return b0 ;
}

int g () {
    int a = 7, w = 9 ;
    return w - a + 9 ;
}

char* c (char* a, int b, bool w) {
    while (b > 8) {
        b = b - 1 ;
        fprintf(stdout, "%d\n", b) ;
    }
    a = "COMP324" ;
    return a ;
}

void h (int b, char* y, bool w) {
    b = b + 9 * 8 ;
    return ;
}

void main() {
    int w = 3 ;
    int v = 9 ;

    int res1 = b (true, f (5, w)) ;
    fprintf(stdout, "%b\n", res1) ;

    fprintf(stdout, "%s\n", c ("yes", g(), false)) ;

    fprintf(stdout, "%s\n", c ("hi", f (w, v) - 31, b(true, g()))) ;
    
    return ;
}