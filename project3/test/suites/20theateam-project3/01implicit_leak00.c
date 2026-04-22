/*!tests!
{
   "input": ["1"],
   "exception": "SecurityException"
}
*/

void main() {
    int secret;
    fscanf(stdin_hi, "%d", &secret);

    int x;

    if (secret == 1) {
        x = 10;
    } else {
        x = 20;
    }

    fprintf(stdout_lo, "%d\n", x);
}