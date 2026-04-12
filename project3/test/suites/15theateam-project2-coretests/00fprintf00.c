/*!tests!
 *
 * {
 *      "input":    ["lol"],
 *      "output":   ["18", "10"]
 * }
 *
 */

void main() {
    int z = 3 ;

    z = 18 ;

    fprintf(stdout, "%d\n", z) ;

    char* w ;
    z = 90 ;

    fscanf(stdin, "%s", &w) ;
    fprintf(stdout, "%d\n", z / 9) ;

    return ;

}