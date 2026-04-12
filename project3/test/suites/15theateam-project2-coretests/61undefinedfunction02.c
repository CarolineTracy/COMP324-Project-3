/*!tests!
 *
 * {
 *    "input":      [],
 *    "exception":     "UndefinedFunction"
 * }
 *
 */

int f (int a, int b, int c) {
    a = a + b + c ;
    fprintf(stdin, "%d\n", h(4, 19)) ;
    return a ;
}

void main() {

    fprintf(stdin, "%d\n", f(1, 2, 3)) ;
    
    return ;
}