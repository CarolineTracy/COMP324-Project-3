/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["8"]
 * }
 * 
 */

int recurs_func (int a, int b) {
    if (a < 0) return b ;
    else return recurs_func (a - 1, b - 1) ;
}

void main() {
    fprintf(stdout, "%d\n", recurs_func(-2, 8)) ;

    return ;
}