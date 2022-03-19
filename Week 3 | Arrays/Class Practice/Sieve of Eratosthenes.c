/*The purpose of the algorithm called "Sieve of Eratosthenes" is to find prime numbers efficiently. This algorithm can be summarized as follows.
Let us list the numbers from 2 up to a certain point, one by one.
This list represents the list of potentially prime numbers. Number 2 is prime, hence we print it, and,
at the same time we remove its integer multiples from the list. The next number to check is number 3
(this is the next one in the list, that has not been removed yet). It must be prime,
since is has not been removed from the list yet, thus we print it and remove its integer multiples from the list. The next number would be 4,
but it has already been removed when visiting number 2. The next prime is 5, print and remove multiples, etc.
Write a program to print the prime numbers up to 999 based on this algorithm. */


#include <stdio.h>
#include <stdbool.h>

int main(void) {
    bool prime[1000];

    /* everything is assumed to be a prime initially */
    for (int n = 0; n < 1000; n += 1)
        prime[n] = true;

    /* the sieve */
    for (int n = 2; n < 1000; n += 1) {    /* traversing the sieve */
        if (prime[n]) {                 /* we found a prime */
            for (int t = n*2; t < 1000; t += n)
                prime[t] = false;
        }
    }

    /* displaying the result */
    for (int n = 2; n < 1000; n += 1)
        if (prime[n])                   /* it remained true -> prime */
            printf("%d ", n);
    printf("\n");

    return 0;
}
