/*!tests!
 *
 * {
 *    "input":      [],
 *    "exception":    "UnboundVariable"
 * }
 *
 */


void main() {
    int x = 2 ;
    {
        {
            x = 84 ;
            int z = 39 ;
        }
        fprintf(stdout, "%d\n", x) ;
        fprintf(stdout, "%d\n", z) ;
    }
    return ;
}