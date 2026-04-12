/*!tests!
 *
 * {
 *    "input":      [],
 *    "exception":     "NoReturn"
 * }
 * 
 */


int f (int a, bool b, int c) {
    if (b0) return 3 + "hi" ;
    else return (a + c) / 0 ;
}

char* g (int w) {
    int c0 = w + 18 ;
    if (c0 > 1) fprintf(stdout, "%s\n", "string1") ;
}

void main() {
    int a = 9 ;
    fprintf(stdout, "%d\n", g(0)) ;
    int a = 10 ;
    fprintf(stdout, "%d\n", f(12, true, 17)) ;
    fprintf(stdout, "%d\n", h("yes", 90)) ;

    return ;
}