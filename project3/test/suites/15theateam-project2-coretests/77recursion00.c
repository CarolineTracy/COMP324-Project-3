/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["6"]
 * }
 * 
 */

int recurs_func (int a, int b) {
    if (a < 0) return b ;
    else return recurs_func (a - 1, b) ;
}

void main() {
    fprintf(stdout, "%d\n", recurs_func(5, 6)) ;

    return ;
}