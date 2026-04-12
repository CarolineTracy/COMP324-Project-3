/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["20", "13"]
 * }
 *
 */


void main() {
    int n = 8 ;
    {
        n = 11 ;
        {
            n = 20 ;
        }
        fprintf(stdout, "%d\n", n) ;
    }
    n = 13 ;
    fprintf(stdout, "%d\n", n) ;
    return ;
}