/*Considering the sequence as a function, realize a recursive function
than returns the nth element of the sequence! The parameters of the
function are: arithmetig_seq(n, start, diff), the sequence number of
the required element, the starting value and the difference. What shall be the base case for this recursion?

Realize a similar (recursive) function that returns the nth element of a geometric sequence.*/

#include <stdio.h>

double arithmetic(int n, double start, double diff) {
    if (n == 0)
        return start; /*base case*/
    else
        return diff + arithmetic(n - 1, start, diff);
}

double geometric(int n, double start, double quot) {
    if (n == 0)
        return start; /*base case*/
    else
        return quot * geometric(n - 1, start, quot);
}


int main(void) {
    for (int n = 0; n < 10; ++n)
        printf("%g  ", arithmetic(n, 5, 1.1));
    printf("\n");

    for (int n = 0; n < 10; ++n)
        printf("%g  ", geometric(n, 5, 2));
    printf("\n");
    return 0;
}
