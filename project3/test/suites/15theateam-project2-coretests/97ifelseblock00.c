/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["3"]
 * }
 *
 */


void main() {
    int x ;
    x = 3 ;

    if (x < 6) int x = 10 ;
    else int x = 19 ;
    fprintf(stdout, "%d\n", x) ;

    return ;
}