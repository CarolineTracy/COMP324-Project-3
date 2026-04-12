/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["18"]
 * }
 * 
 */

int recurs_func (int a, int b) {
    if (a < 0) return b ;
    else return recurs_func (a - 1, b - 1) ;
}

void main() {
    int c = 18 ;
    fprintf(stdout, "%d\n", c) ;

    return ;
}