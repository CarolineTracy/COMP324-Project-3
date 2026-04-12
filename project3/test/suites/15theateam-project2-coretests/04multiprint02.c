/*!tests!
 *
 * {
 *    "input":      ["1"],
 *    "output":     ["1", "1", "-9", "18", "5", "1", "1"]
 * }
 * 
 * {
 *    "input":      ["-6"],
 *    "output":     ["-6", "-6", "-16", "-108", "-2", "-6", "-6"]
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
    fprintf(stdout, "%d\n", a + 4) ;
    fprintf(stdout, "%d\n", a) ;
    fprintf(stdout, "%d\n", a) ;

    return ;
}