/*Calculate the sum of divisors for a number entered by the user.
(e.g. for 6: 1+2+3+6 = 12.) Modify your algorithm to exclude the number itself from the summation. What should be changed in the program?

Perfect number is an integer that equals to this sum (so the sum of divisors, including 1,
excluding the number itself). The first perfect number is 6 as 1+2+3=6. The next two are 28 and 496.
Print out if the number entered by the user is a perfect number or not. */

#include <stdio.h>

int main(void) {
    int number;
    printf("The number: ");
    scanf("%d", &number);

    int divisorsum = 0;
    /* divisor>number/2 can not occur (only the number itself could satisfy it) */
    for (int divisor = 1; divisor <= number / 2; divisor = divisor + 1)
        if (number % divisor == 0)
            divisorsum = divisorsum + divisor;

    if (divisorsum == number)
        printf("This is a perfect number.\n");
    else
        printf("The number is not perfect, %d != %d.\n", number, divisorsum);

    return 0;
}
