/*!tests!
 *
 * {
 *    "input":      ["true", "false", "10"],
 *    "output":     ["hi", " more strings ", "true false", "10"]
 * }
 * 
 * {
 *    "input":      ["false", "false", "1"],
 *    "output":     ["bye", " more strings ", "false false", "1"]
 * }
 * 
 * {
 *    "input":      ["true", "true", "-4"],
 *    "output":     ["hi", "what do i write here...", "true true", "-4"]
 * }
 *
 */


void main() {
    bool b ;
    fscanf(stdin, "%b", &b) ;

    if (b) fprintf(stdout, "hi\n") ;
    else fprintf(stdout, "bye\n") ;

    bool b0 ;
    fscanf(stdin, "%b", &b0) ;

    if (!(b && b0)) fprintf(stdout, " more strings \n") ;
    else fprintf(stdout, "what do i write here...\n") ;

    if (3 == 1 + 2 - 7 + 7) fprintf(stdout, "%b %b\n", b, b0) ;

    int i = 1 ;
    if (1 != 1) fprintf(stdout, "%s\n", s1) ;
    else fscanf(stdin, "%d", &i) ;

    fprintf(stdout, "%d\n", i) ;

    return ;
}