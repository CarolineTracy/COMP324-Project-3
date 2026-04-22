/*!tests!
 *
 * {
 *    "input":      ["-", "h a h a h a"],
 *    "output":     ["-", "     ", "mac and cheese", "h", "", " abcd", " ", "-", "[]", "does this work?"]
 * }
 * 
 */

void main() {
    char* a, d ;
    char* b = "     ", c = "mac and cheese", e = "", f = " abcd", g = " ";

    // LOW --> LOW
    fscanf(stdin_lo, "%s", &a) ;

    // HIGH --> LOW (will leak later)
    fscanf(stdin_hi, "%s", &d) ;

    // LOW --> LOW
    fprintf(stdout_lo, "%s\n", a) ;

    fprintf(stdout_lo, "%s\n", b) ;
    fprintf(stdout_lo, "%s\n", c) ;

    // HIGH --> LOW
    fprintf(stdout_lo, "%s\n", d) ;

    fprintf(stdout_lo, "%s\n", e) ;
    fprintf(stdout_lo, "%s\n", f) ;
    fprintf(stdout_lo, "%s\n", g) ;

    // LOW --> HIGH
    fprintf(stdout_hi, "%s\n", a) ;

    // Reassignment
    // resets label to LOW
    a = "[]" ; 

    // LOW --> LOW
    fprintf(stdout_lo, "%s\n", a) ;

    fprintf(stdout_lo, "does this work?") ;

    return ;
}