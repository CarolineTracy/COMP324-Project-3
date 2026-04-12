/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["2", "0", "5", "9", "83", "0", "7", "18", "40", "19", "53", "-6", "20", "99", "0", "7", "44", "-22", "-3", "11", "11", "7", "44", "-22", "-3"]
 * }
 *
 */


void main() {
    int a = 2 ;
    fprintf(stdout, "%d\n", a) ;
    a = 0 ;
    fprintf(stdout, "%d\n", a) ;
    {
        int a = 5 ;
        int b = 9 ;
        fprintf(stdout, "%d\n%d\n", a, b) ;
        a = 83 ;
        fprintf(stdout, "%d\n", a) ;
        {
            int a = 0 ;
            int b = 7 ;
            int c = 18 ;
            fprintf(stdout, "%d\n%d\n%d\n", a, b, c) ;
            c = 40 ;
            fprintf(stdout, "%d\n", c) ;
            {
                int a = 19 ;
                int b = 53 ;
                int c = -6 ;
                int d = 20 ;
                fprintf(stdout, "%d\n%d\n%d\n%d\n", a, b, c, d) ;
                b = 99 ;
                fprintf(stdout, "%d\n", b) ;
                {
                    int a = 0 ;
                    int b = 7 ;
                    int c = 44 ;
                    int d = -22 ;
                    int e = -3 ;
                    fprintf(stdout, "%d\n%d\n%d\n%d\n%d\n", a, b, c, d, e) ;
                    a = 11 ;
                    fprintf(stdout, "%d\n", a) ;
                    {
                        fprintf(stdout, "%d\n%d\n%d\n%d\n%d\n", a, b, c, d, e) ;
                    }
                }
            }
        }
    }
    return ;
}