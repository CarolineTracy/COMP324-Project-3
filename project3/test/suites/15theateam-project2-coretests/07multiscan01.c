/*!tests!
 *
 * {
 *    "input":      ["one two three four 5 6"],
 *    "output":     ["one", "two", "three", "four", "5", "6"]
 * }
 * 
 * {
 *    "input":      [".  seven eight nine 10  0"],
 *    "output":     [".", "seven", "eight", "nine", "10", "0"]
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