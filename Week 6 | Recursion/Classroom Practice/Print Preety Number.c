/*Write a function that prints the positive integer received as a parameter in an easy to
read format: form groups of three digits and separate them by spaces.
Example: 16 077 216. Test for other values, too: 999, 1000, 12, 0, 1000222.*/

#include <stdio.h>

void printnum(int n) {
    /* If we have more than 3 digits */
    if (n / 1000 > 0) {
        printnum(n / 1000);        /* Cut last 3 digits and call the function recursively */
        printf(" %03d", n % 1000); /* Print a space and the last 3 digits */
    }
    else
        printf("%d", n);           /* Otherwise we print the number without modifications */
}

int main(void) {
    printnum(16077216);

    return 0;
}
