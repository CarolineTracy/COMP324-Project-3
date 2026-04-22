/*!tests!
 *
 * {
 *    "input":      ["true", "19", "27", "0", "38920"],
 *    "output":     ["7", "6", "5", "4", "3", "19", "27", "0", "38920", "done"]
 * }
 * 
 */

void main() {
    int x = 7 ;
    
    // LOW --> LOW
    while (x > 2) {
        fprintf(stdout_lo, "%d\n", x) ;
        x = x - 1 ;
    }

    while (false) {
        fprintf(stdout_lo, "hello") ;
    }

    x = 10 ;
    bool b ;
    fscanf(stdin_lo, "%b", &b) ;

    // HIGH --> LOW
    while (!b || (x >= 6)) {
        int y ;
        fscanf(stdin_hi, "%d", &y) ;
        fprintf(stdout_lo, "%d\n", y) ;
        b = !b ;
        x = x - 2 ;
    }

    // LOW --> HIGH
    fprintf(stdout_hi, "done\n") ;

    return ;
}