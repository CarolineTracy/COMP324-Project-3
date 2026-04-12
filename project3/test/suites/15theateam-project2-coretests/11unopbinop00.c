/*!tests!
 *
 * {
 *    "input":      ["3", "7", "-1", "0"],
 *    "output":     ["7", "-7", "11", "-8", "0", "2", "2", "-12"]
 * }
 * 
 * {
 *    "input":      ["-19", "0", "11", "-120"],
 *    "output":     ["-15", "15", "4", "88", "0", "2", "2", "-12"]
 * }
 *
 */



void main() {
    int a, b, c, d, e = 8, f = -10;

    fscanf(stdin, "%d", &a) ;
    fscanf(stdin, "%d", &b) ;
    fscanf(stdin, "%d", &c) ;
    fscanf(stdin, "%d", &d) ;

    a = a + 4 ;
    fprintf(stdout, "%d\n", a) ;
    fprintf(stdout, "%d\n", -a) ;

    b = 4 - -b ;
    fprintf(stdout, "%d\n", b) ;

    fprintf(stdout, "%d\n", c * 8) ;

    d = d * 0;
    fprintf(stdout, "%d\n", d) ;

    fprintf(stdout, "%d\n", e / 4) ;
    fprintf(stdout, "%d\n", e % 3) ;

    fprintf(stdout, "%d\n", f - 2) ;

    return ;
}