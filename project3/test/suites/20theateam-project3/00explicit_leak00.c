/*!tests!
{
   "input": ["5"],
   "exception": "SecurityException"
}
*/

void main() {
    int x;
    fscanf(stdin_hi, "%d", &x);
    fprintf(stdout_lo, "%d\n", x);
}