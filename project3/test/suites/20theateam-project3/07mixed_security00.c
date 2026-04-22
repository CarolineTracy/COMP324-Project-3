/*!tests!
{
   "input": ["5", "10"],
   "output": ["5", "10"]
}
*/

void main() {
    int pub, secret;

    fscanf(stdin_lo, "%d", &pub);
    fscanf(stdin_hi, "%d", &secret);

    fprintf(stdout_lo, "%d\n", pub);    
    fprintf(stdout_hi, "%d\n", secret);
}