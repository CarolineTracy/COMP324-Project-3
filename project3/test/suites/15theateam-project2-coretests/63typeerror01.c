/*!tests!
 *
 * {
 *    "input":      ["7"],
 *    "exception":     "TypeError"
 * }
 * 
 */



void main() {
    int a ;
    fscanf(stdin, "%d", &a) ;

    fprintf(stdout, "%d\n", a) ;
    fprintf(stdout, "%d\n", a) ;
    fprintf(stdout, "%d\n", a - 10) ;
    fprintf(stdout, "%d\n", a * 18) ;
    fprintf(stdout, "%s\n", a + 4) ;
    fprintf(stdout, "%d\n", a) ;
    fprintf(stdout, "%s\n", a) ;

    return ;
}