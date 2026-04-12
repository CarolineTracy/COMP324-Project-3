/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["4", "4", "18", "18", "0", "0", "11", "11", "66"]
 * }
 *
 */



void main() {
    int y ;
    y = 4 ;
    fprintf(stdout, "%d\n", y) ;

    {
        fprintf(stdout, "%d\n", y) ;
        y = 18 ;
        fprintf(stdout, "%d\n", y) ;

        {
            fprintf(stdout, "%d\n", y) ;
            y = 0 ;
            fprintf(stdout, "%d\n", y) ;
        }

        fprintf(stdout, "%d\n", y) ;
        y = 11 ;
        fprintf(stdout, "%d\n", y) ;
    }

    fprintf(stdout, "%d\n", y) ;
    y = 66 ;
    fprintf(stdout, "%d\n", y) ;

    return ;
}