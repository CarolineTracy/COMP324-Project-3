/*!tests!
 *
 * {
 *    "input":      ["6", "5"],
 *    "output":     ["false", "true", "true", "true", "false", "false"]
 * }
 * 
 */

void main() {
    int h ;
    int i ;

    fscanf(stdin_lo, "%d", &h) ;

    fscanf(stdin_hi, "%d", &i) ;


    fprintf(stdout_lo, "%b\n", h == i) ; 

    bool j = h != i ;
    fprintf(stdout_lo, "%b\n", j) ; 

    fprintf(stdout_lo, "%b\n", h > i) ;
    fprintf(stdout_lo, "%b\n", h >= i) ;

    j = h < i ;
    fprintf(stdout_lo, "%b\n", j) ; 

    bool k = h <= i ;
    fprintf(stdout_lo, "%b\n", k) ; 

    return ;
}