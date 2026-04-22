/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["-27"]
 * }
 *
 */

void main() {
    int a = 2 ;
    {
        int b = 9 ;
        {
            int c = 18 ;
            {
                int d = 20 ;
                {
                    int e = -3 ;
                    {
                        // LOW → LOW
                        fprintf(stdout_lo, "%d\n", (a + b + c - d) * e) ;

                        // LOW → HIGH
                        fprintf(stdout_hi, "%d\n", (a + b + c - d) * e) ;

                        // HIGH → HIGH
                        int h = (a + b + c - d) * e ;
                        fprintf(stdout_hi, "%d\n", h) ;

                        // HIGH → LOW
                        fprintf(stdout_lo, "%d\n", h) ;
                    }
                }
            }
        }
    }
    return ;
}