/*!tests!
 *
 * {
 *    "input":      [],
 *    "exception":   "MultipleDeclaration"
 * }
 *
 */


void main() {
    int a = 2 ;
    fprintf(stdout, "%d\n", a) ;
    {
        int a = 5 ;
        int b = 9 ;
        fprintf(stdout, "%d\n%d\n", a, b) ;
        {
            int a = 0 ;
            int b = 7 ;
            int c = 18 ;
            fprintf(stdout, "%d\n%d\n%d\n", a, b, c) ;
            {
                int a = 19 ;
                int b = 53 ;
                int c = -6 ;
                int d = 20 ;
                fprintf(stdout, "%d\n%d\n%d\n%d\n", a, b, c, d) ;
                {
                    int a = 0 ;
                    int b = 7 ;
                    int c = 44 ;
                    int d = -22 ;
                    int e = -3 ;
                    fprintf(stdout, "%d\n%d\n%d\n%d\n%d\n", a, b, c, d, e) ;
                    {
                        fprintf(stdout, "%d\n%d\n%d\n%d\n%d\n", a, b, c, d, e) ;
                    }
                }
            }
        }
    }
    int a ;
    return ;
}