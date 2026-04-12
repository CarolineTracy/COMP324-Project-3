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
                        fprintf(stdout, "%d\n", (a + b + c - d) * e) ;
                    }
                }
            }
        }
    }
    return ;
}