/*!tests!
 *
 * {
 *    "input":      [],
 *    "exception":  "MultipleDeclaration"
 * }
 *
 */

int f (int x, int y) {
    while (true) {
        int w = 4 + 9 ;
        int e = 3 ;
        {
            {
                int o = 0 ;
                int i = 9 ;
                int o = 18 ;
            }
        }
    }
    return x + y ;
}

void main() {
    fprintf(stdout, "%d\n", f(17, 4)) ;
    return ;
}