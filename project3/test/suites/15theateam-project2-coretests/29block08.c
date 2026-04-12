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
        int b = 0 ;
    }
    {
        int b = 9 ;
        {
            {
                int c = 9;
            }
            int c = 18 ;
            {
                int d = 20 ;
                {
                    int a = 12 ;
                }
                {
                    int e = -3 ;
                    {
                        int e = 81 ;
                    }
                    {
                        fprintf(stdout, "%d\n", (a + b + c - d) * e) ;
                    }
                }
            }
        }
    }
    return ;
}