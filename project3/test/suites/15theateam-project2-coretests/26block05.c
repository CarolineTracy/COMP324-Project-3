/*!tests!
 *
 * {
 *    "input":      [],
 *    "output":     ["8", "9"]
 * }
 *
 */


int f() {
    int x = 8 ;
    fprintf(stdout, "%d\n", x) ;
    {
        return x + 1 ;
        int y, z = 13 ;
        fprintf(stdout, "%d\n", z) ;
        fscanf(stdin, "%d\n", &y) ;
        return y - z ;
    }
    return 30;
}

void main() {
    fprintf(stdout, "%d\n", f()) ;
    return ;
}