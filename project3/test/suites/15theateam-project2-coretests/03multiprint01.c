/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["3", "3", "-7", "54", "7", "3", "3", "3", "3", "8 string1", "0 9"]
 * }
 * 
 */



void main() {
    int a = 3 ;

    fprintf(stdout, "%d\n", a) ;
    fprintf(stdout, "%d\n", a) ;
    fprintf(stdout, "%d\n", a - 10) ;
    fprintf(stdout, "%d\n", a * 18) ;
    fprintf(stdout, "%d\n", a + 4) ;
    fprintf(stdout, "%d\n", a) ;
    fprintf(stdout, "%d\n", a) ;

    char* s1 = "string1" ;

    fprintf(stdout, "%d\n%d\n%d %s\n%d %d\n", a, a, a + 5, s1, 0, 9) ;

    return ;
}