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
                int o, l, k, f, d ;
                int o ;
            }
        }
    }
    return x + y ;
}

void main() {
    fprintf(stdout, "%d\n", f(17, 4)) ;
    return ;
}