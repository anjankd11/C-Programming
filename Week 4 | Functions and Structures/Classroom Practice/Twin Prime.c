/*A twin prime is a prime number that is either 2 less or 2 more than another prime number
- for example, either member of the twin prime pair (41, 43). In other words, a twin prime is a prime that has a prime gap of two.
The first couple of twin primes are (3, 5), (5, 7) and (11, 13).
Write a C program to find the 60th twin prime!
Extend the program to check whether the number between the twin primes has any digit equal to 5.
Avoid code duplication, use functions wherever reasonable! Follow the top-down design methodology. */

#include <stdio.h>
#include <stdbool.h>

/* decides whether the number is a prime or not */
int prime(int number) {
    for (int divisor = 2; divisor < number; divisor++)
        if (number % divisor == 0)
            return 0;
    return 1;
}

/* decides whether the number has a specific digit included or not */
int contains(int number, int digit) {
    while (number > 0) {
        if (number % 10 == digit)
            return 1;
        number /= 10;
    }
    return 0;
}

int main(void) {
    int number, i;

    /* initialization */
    number = 1;
    i = 0;
    while (i < 60) {
        /* find next twin primes */
        number += 2;
        while (!(prime(number) && prime(number + 2)))
            number += 2;
        ++i;
    }
    printf("%dth twin prime: %d %d\n", 60, number, number+2);

    /* second part: check if the number inbetween contains digit 5 */
    printf("The number inbetween %s digit 5.\n", contains(number + 1, 5) ? "does contain":"does not contain");

    return 0;
}
