/*!tests!
 *
 * {
 *    "input":      [],
 *    "exception":     "UnboundVariable"
 * }
 *
 */

int f (int a, int b) {
    int c = a * b ;
    return (c + b) + w ;
}

bool b (bool b0, int v) {
    bool b1 = !b0 ;
    if (v >= 5) return b1 ;
    return b0 ;
}

int g () {
    int a = 7, w = 9 ;
    return w - a + v ;
}

char* c (char* a, int b, bool w) {
    while (b > 8) {
        b = b - 1 ;
        fprintf(stdin, "%d\n", b) ;
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
    fprintf(stdin, "%b\n", res1) ;

    int res2 = c ("yes", g(), false) ;
    fprintf(stdin, "%d\n", res2) ;

    int res3 = c ("hi", f (w, v) - 31, b(true, g())) ;
    fprintf(stdin, "%d\n", res3) ;
    
    return ;
}