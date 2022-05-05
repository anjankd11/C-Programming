//Write a recursive function that calculates the power according to these rules!
// The parameters should be the x and n, and the return value should be (xn). Print the first sixteen powers of 2.

#include<stdio.h>

double power(double base, unsigned exponent) {
    /* the 0th power of anything is 1 */
    if (exponent == 0)
        return 1;

    if (exponent % 2 == 0)
        /* if even, it is the same as if the base was squared and the exponent divided by 2 */
        return power(base * base, exponent / 2);
    else
        /* otherwise base * base to the power of k-1 */
        return base * power(base, exponent - 1);
}

int main(void) {
    for (int i = 0; i < 16; ++i)
        printf("%d %g\n", i, power(2, i));

    return 0;
}
