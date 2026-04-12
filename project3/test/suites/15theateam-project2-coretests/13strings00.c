/*!tests!
 *
 * {
 *    "input":      ["-", "h a h a h a"],
 *    "output":     ["-", "     ", "mac and cheese", "h", "", " abcd", " ", "-", "[]", "does this work?"]
 * }
 * 
 * {
 *    "input":      [".", "i'm tired"],
 *    "output":     [".", "     ", "mac and cheese", "i'm", "", " abcd", " ", ".", "[]", "does this work?"]
 * }
 * 
 */



void main() {
    char* a, b = "     ", c = "mac and cheese", d, e = "", f = " abcd", g = " ";

    fscanf(stdin, "%s", &a) ;
    fscanf(stdin, "%s", &d) ;

    fprintf(stdout, "%s\n", a) ;

    fprintf(stdout, "%s\n", b) ;

    fprintf(stdout, "%s\n", c) ;

    fprintf(stdout, "%s\n", d) ;

    fprintf(stdout, "%s\n", e) ;

    fprintf(stdout, "%s\n", f) ;

    fprintf(stdout, "%s\n", g) ;

    fprintf(stdout, "%s\n", a) ;

    a = "[]" ;

    fprintf(stdout, "%s\n", a) ;

    fprintf(stdout, "does this work?") ;

    return ;
}