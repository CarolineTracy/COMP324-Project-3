/*!tests!
 *
 * {
 *    "input":      ["Cat", "Hamster", "Mouse", "Dog"],
 *    "output":     ["Hamster", "Mouse", "Mouse"]
 * }
 * 
 * {
 *    "input":      ["A", "B", "C", "D"],
 *    "output":     ["B", "C", "C"]
 * }
 * 
 */

void main() {
    char* s ;

    fscanf(stdin, "%s", &s) ;
    fscanf(stdin, "%s", &s) ;

    fprintf(stdout, "%s\n", s) ;
    
    fscanf(stdin, "%s", &s) ;

    fprintf(stdout, "%s\n", s) ;
    fprintf(stdout, "%s\n", s) ;

    fscanf(stdin, "%s", &s) ;

    return ;
}