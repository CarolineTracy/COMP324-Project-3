/*!tests!
 *
 * {
 *    "input":      ["4"],
 *    "exception":     "UnboundVariable"
 * }
 * 
 * {
 *    "input":      ["-6"],
 *    "exception":     "UnboundVariable"
 * }
 * 
 */


void main() {
    fscanf(stdin, "%d", &a) ;

    fprintf(stdout, "%d\n", a) ;
    fprintf(stdout, "%d\n", a) ;
    fprintf(stdout, "%d\n", a - 10) ;
    fprintf(stdout, "%d\n", a * 18) ;
    fprintf(stdout, "%d\n", a + 4) ;
    fprintf(stdout, "%d\n", a) ;
    fprintf(stdout, "%d\n", a) ;

    return ;
}