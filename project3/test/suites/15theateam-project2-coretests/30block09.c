/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["-3", "20"]
 * }
 *
 */


void main() {
    int x = 2 ;
    {
        {
            int x = 25 ;
        }
        int y = 9 ;
        {
            int x = 18 ;
            {
                {
                    int x = 36 ;
                }
                int y = 20 ;
                {
                    int x = -3 ;
                    {
                        int y = 84 ;
                    }
                    {
                        fprintf(stdout, "%d\n", x) ;
                        fprintf(stdout, "%d\n", y) ;
                    }
                }
            }
        }
    }
    return ;
}