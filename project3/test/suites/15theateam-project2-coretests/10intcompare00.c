/*!tests!
 *
 * {
 *    "input":      ["6", "5"],
 *    "output":     ["false", "true", "true", "true", "false", "false"]
 * }
 * 
 * {
 *    "input":      ["-9", "-4"],
 *    "output":     ["false", "true", "false", "false", "true", "true"]
 * }
 * 
 * {
 *    "input":      ["0", "1"],
 *    "output":     ["false", "true", "false", "false", "true", "true"]
 * }
 * 
 * {
 *    "input":      ["8", "8"],
 *    "output":     ["true", "false", "false", "true", "false", "true"]
 * }
 *
 */


void main() {
    int h ;
    int i ;

    fscanf(stdin, "%d", &h) ;
    fscanf(stdin, "%d", &i) ;

    fprintf(stdout, "%b\n", h == i) ;

    bool j = h != i ;
    fprintf(stdout, "%b\n", j) ;

    fprintf(stdout, "%b\n", h > i) ;
    fprintf(stdout, "%b\n", h >= i) ;

    j = h < i ;
    fprintf(stdout, "%b\n", j) ;

    bool k = h <= i ;
    fprintf(stdout, "%b\n", k) ;

    return ;
}