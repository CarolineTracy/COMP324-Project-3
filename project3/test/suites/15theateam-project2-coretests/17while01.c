/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["7", "25"]
 * }
 *
 */

int f() {
    int i = 8 ;
    while (i > 4) {
        i = i - 1 ;
        return i ;
    }
    return 4 ;
}

int g() {
    int j = 15 ;
    while (j < 30) {
        return j + 10 ;
        j = j - 9 ;
        fprintf(stdout, "%d\n", j) ;
        int w = 10 ;
        fprintf(stdout, "%d\n", w) ;
        return 18 ;
        return j ;
    }
}

void main() {
    fprintf(stdout, "%d\n", f()) ;
    fprintf(stdout, "%d\n", g()) ;
    return ;
}