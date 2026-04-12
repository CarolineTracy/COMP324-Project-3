/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["84"]
 * }
 *
 */


void main() {
    int x = 2 ;
    {
        x = 9 ;
        {
            x = 18 ;
            {
                {
                    x = 36 ;
                }
                x = 20 ;
                {
                    x = -3 ;
                    {
                        x = 84 ;
                    }
                    {
                        fprintf(stdout, "%d\n", x) ;
                    }
                }
            }
        }
    }
    return ;
}