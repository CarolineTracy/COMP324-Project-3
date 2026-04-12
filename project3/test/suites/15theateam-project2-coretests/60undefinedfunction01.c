/*!tests!
 *
 * {
 *    "input":      [],
 *    "exception":     "UndefinedFunction"
 * }
 *
 */

void main() {

    fprintf(stdin, "%s\n", cc("lol")) ;
    fprintf(stdin, "%d\n", w(7, 9, "i")) ;
    fprintf(stdin, "%d\n", b(true, false, 891)) ;
    fprintf(stdin, "%d\n", f(4, 19)) ;
    
    return ;
}