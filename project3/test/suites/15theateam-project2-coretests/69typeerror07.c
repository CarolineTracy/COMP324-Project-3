/*!tests!
 *
 * {
 *    "input":      [],
 *    "exception":     "TypeError"
 * }
 * 
 */

bool b (bool b1, bool b2) {
    return !b1 && b2 ;
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
    bool d = b() ;
    fprintf(stdout, "%d\n", d) ;
    return ;
}