/*The Fibonacci-series is defined as: F0=0, F1=1, Fn=Fn-1+Fn-2.
Write a recursive function to calculate the nth element! Test your function for n=40!
What happens? (Hint: remember the lecture topic.)

Trace your program in the debugger. Start it and see how it works for n=5.
You may implement your own tracing method: your fib() function should first print the value of the parameter (n).*/

#include <stdio.h>

/* Fibonacci series */
int fib(int n) {
    /* base cases (terminating terms) */
    if (n == 0) return 0; /* element 0. is 0 */
    if (n == 1) return 1; /* element 1. is 1 */

    /* general term */
    return fib(n - 1) + fib(n - 2); /* the nth element is the sum of the previous two */
}

int main(void) {
    for (int i = 0; i < 40; i++)
        printf("%d\n", fib(i));

    return 0;
}
