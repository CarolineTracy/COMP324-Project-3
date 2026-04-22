/*!tests!
 *
 * {
 *    "input":      ["true", "false", "10"],
 *    "output":     ["hi", " more strings ", "true false", "10"]
 * }
 * 
 */

void main() {
    bool b ;
    fscanf(stdin_lo, "%b", &b) ;

    // LOW --> LOW
    if (b) fprintf(stdout_lo, "hi\n") ;
    else fprintf(stdout_lo, "bye\n") ;

    bool b0 ;
    fscanf(stdin_hi, "%b", &b0) ;

    // ------------------------
    // HIGH --> LOW 
    if (!(b && b0)) fprintf(stdout_lo, " more strings \n") ;
    else fprintf(stdout_lo, "what do i write here...\n") ;


    // LOW + HIGH --> HIGH
    if (3 == 1 + 2 - 7 + 7)
        fprintf(stdout_hi, "%b %b\n", b, b0) ;

    int i = 1 ;


    // LOW --> LOW
    if (1 != 1) fprintf(stdout_lo, "%s\n", s1) ;
    else fscanf(stdin_lo, "%d", &i) ; 

    // LOW --> HIGH
    fprintf(stdout_hi, "%d\n", i) ;

    return ;
}