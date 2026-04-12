/*!tests!
 *
 * {
 *    "input":      ["1", "0", "3"],
 *    "output":     ["9", "9", "0", "3", "1"]
 * }
 * 
 * {
 *    "input":      ["-7", "-9", "6"],
 *    "output":     ["9", "9", "-9", "6", "-7"]
 * }
 *
 */

void main() {
    int x = 9, y = 8, z, a, b = 1 ;

    fscanf(stdin, "%d", &z) ;
    fscanf(stdin, "%d", &a) ;
    fscanf(stdin, "%d", &b) ;

    fprintf(stdout, "%d\n", x) ;
    fprintf(stdout, "%d\n", y + 1) ;
    fprintf(stdout, "%d\n", a) ;
    fprintf(stdout, "%d\n", b) ;
    fprintf(stdout, "%d\n", z) ;

    return ;
}