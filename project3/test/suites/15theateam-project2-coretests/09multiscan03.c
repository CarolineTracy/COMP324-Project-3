/*!tests!
 *
 * {
 *    "input":      ["ten\nnine\neight\nseven\n6\n5"],
 *    "output":     ["ten", "nine", "eight", "seven", "6", "5"]
 * }
 * 
 * {
 *    "input":      [" four  \n three\ntwo\n  one  \n0 \n-1"],
 *    "output":     ["four", "three", "two", "one", "0", "-1"]
 * }
 * 
 */

void main() {
    char* a, b, c, d ;
    int e, f ;

    fscanf(stdin, "%s", &a) ;
    fscanf(stdin, "%s", &b) ;
    fscanf(stdin, "%s", &c) ;
    fscanf(stdin, "%s", &d) ;
    fscanf(stdin, "%d", &e) ;
    fscanf(stdin, "%d", &f) ;

    fprintf(stdout, "%s\n", a) ;
    fprintf(stdout, "%s\n", b) ;
    fprintf(stdout, "%s\n", c) ;
    fprintf(stdout, "%s\n", d) ;
    fprintf(stdout, "%d\n", e) ;
    fprintf(stdout, "%d\n", f) ;

    return ;
}