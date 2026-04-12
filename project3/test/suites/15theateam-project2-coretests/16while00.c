/*!tests!
 *
 * {
 *    "input":      ["true", "19", "27", "0", "38920"],
 *    "output":     ["7", "6", "5", "4", "3", "19", "27", "0", "38920", "done"]
 * }
 * 
 * {
 *    "input":      ["false", "-111", "45", "-7"],
 *    "output":     ["7", "6", "5", "4", "3", "-111", "45", "-7", "done"]
 * }
 *
 */


void main() {
    int x = 7 ;
    
    while (x > 2) {
        fprintf(stdout, "%d\n", x) ;
        x = x - 1 ;
    }

    while (false) {
        fprintf(stdout, "hello") ;
    }

    x = 10 ;
    bool b ;
    fscanf(stdin, "%b", &b) ;

    while (!b || (x >= 6)) {
        int y ;
        fscanf(stdin, "%d", &y) ;
        fprintf(stdout, "%d\n", y) ;
        b = !b ;
        x = x - 2 ;
    }

    fprintf(stdout, "done\n") ;

    return ;
}