/*!tests!
 *
 * {
 *    "input":      [],
 *    "exception":     "UndefinedFunction"
 * }
 *
 */

int w (int u, int h, char* t) {
    int y = u + h ;
    fprintf(stdin, "%d\n", u) ;
    fprintf(stdin, "%d\n", h) ;
    fprintf(stdin, "%s\n", t) ;
    fprintf(stdin, "%d\n", y) ;
    return y + h - u ;
}

char* cc (char* c0) {
    fprintf(stdin, "%s\n", c0) ;
    if (true) return c0 ;
    else return "whoops" ;
}

bool b (bool b1, bool b7, int d) {
    while (b1) {
        b1 = !b1 ;
        fprintf(stdin, "%b\n", b7) ;
    }
    return b1 || b7 ;
}

void main() {

    fprintf(stdin, "%s\n", cc("lol")) ;
    fprintf(stdin, "%d\n", w(7, 9, "i")) ;
    fprintf(stdin, "%b\n", b(true, false, 891)) ;
    fprintf(stdin, "%d\n", f(4, 19)) ;
    
    return ;
}