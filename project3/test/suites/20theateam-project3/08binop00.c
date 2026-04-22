/*!tests!
{
   "input": ["5"],
   "exception": "SecurityException"
}
*/

void main() {
    int secret;
    fscanf(stdin_hi, "%d", &secret);

    int x = secret + 1;

    fprintf(stdout_lo, "%d\n", x);
}