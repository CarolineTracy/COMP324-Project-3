/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["8"]
 * }
 *
 */


void main() {
    int n = 8 ;
    {
        {
            int n = 20 ;
        }
        fprintf(stdout, "%d\n", n) ;
    }
    n = 13 ;
    return ;
}