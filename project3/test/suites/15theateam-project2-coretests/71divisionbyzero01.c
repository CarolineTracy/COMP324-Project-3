/*!tests!
 *
 * {
 *    "input":      [],
 *    "exception":     "Division_by_zero"
 * }
 * 
 */

int f(int a, int c) {
    int b = (a + c) / c ;
    return b ;
}

void main() {
    int c = 0 ;
    fprintf(stdout, "%d\n", f(6, c)) ;
    return ;
}