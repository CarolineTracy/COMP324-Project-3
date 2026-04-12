/*!tests!
 *
 * {
 *      "input":    ["true", "true"],
 *      "output":   ["true", "true", "true", "false", "false", "true", "false", "true", "false", "true", "false"]
 * }
 * 
 * {
 *      "input":    ["true", "false"],
 *      "output":   ["false", "true", "false", "true", "true", "true", "false", "false", "false", "true", "false"]
 * }
 * 
 * {
 *      "input":    ["false", "true"],
 *      "output":   ["false", "true", "false", "true", "false", "false", "true", "true", "true", "true", "false"]
 * }
 * 
 * {
 *      "input":    ["false", "false"],
 *      "output":   ["false", "false", "true", "false", "false", "true", "false", "true", "true", "true", "false"]
 * }
 *
 */

void main() {
    bool b1 ;
    bool b2 ;

    fscanf(stdin, "%b", &b1) ;
    fscanf(stdin, "%b", &b2) ;

    bool b3 = b1 && b2 ;
    fprintf(stdout, "%b\n", b3) ;
    fprintf(stdout, "%b\n", b1 || b2) ;
    fprintf(stdout, "%b\n", b1 == b2) ;
    fprintf(stdout, "%b\n", b1 != b2) ;

    b3 = b1 > b2 ;
    fprintf(stdout, "%b\n", b3) ;

    bool b4 = b1 >= b2 ;
    fprintf(stdout, "%b\n", b4) ;
    fprintf(stdout, "%b\n", b1 < b2) ;

    b4 = b1 <= b2 ;
    fprintf(stdout, "%b\n", b4) ;

    fprintf(stdout, "%b\n", !b1) ;

    fprintf(stdout, "%b\n", true) ;
    fprintf(stdout, "%b\n", false) ;

    return ;

}