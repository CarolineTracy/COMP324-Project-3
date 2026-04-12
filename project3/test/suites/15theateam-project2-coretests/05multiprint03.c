/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["24", "24", "14", "432", "28", "24", "24"]
 * }
 * 
 */



void main() {
    int a = 24 ;

    fprintf(stdout, "%d\n", a) ;
    fprintf(stdout, "%d\n", a) ;
    fprintf(stdout, "%d\n", a - 10) ;
    fprintf(stdout, "%d\n", a * 18) ;
    fprintf(stdout, "%d\n", a + 4) ;
    fprintf(stdout, "%d\n", a) ;
    fprintf(stdout, "%d\n", a) ;

    return ;
}