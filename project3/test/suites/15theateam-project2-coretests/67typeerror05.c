/*!tests!
 *
 * {
 *    "input":      [],
 *    "exception":     "TypeError"
 * }
 * 
 */

int f (int a, int b) {
    return a + b ;
}

char* c (char* u, int a, bool b0) {
    int z = 8 + a ;
    while (z > 4) {
        z = z - 1 ;
    } 
    return u ;
}

void main() {
    char* w = "hello" ;
    fprintf(stdout, "%s\n", w) ;
    int d = c(w, 8, false, 9) ;
    fprintf(stdout, "%d\n", d) ;
    return ;
}