/*Write a function that takes two parameters:
a positive integer value, and the base of a numeral system.
Print the value in the given numeral system.
Why is the solution much simpler using recursion than an iterative solution? */

#include <stdio.h >

/* This works for numeral systems with base r<=10  */
void convert(int n, int r) {
    /* If n>r, recursive call */
    if (n / r > 0)
        convert(n / r, r);
    /* print the remainder (last digit) */
    printf("%d", n % r);
}

/* This version can make use of the whole English alphabet (up to base 36) */
void convert2(int n, int r) {
    char *s = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    /* If there are more digits to print, recursive call */
    if(n / r > 0)
        convert2(n / r, r);
    /* print the remainder (last digit) */
    putchar(a[n % r]);
}

int main(void) {
    convert(27, 5);  /* 102 */
    printf("\n");
    convert(13, 2);  /* 1101 */
    printf("\n");
    convert2(64519, 16);  /* FC07 */

    return 0;
}
