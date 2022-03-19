#include <stdio.h>

int main(void) {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    int divisor;
    divisor = 2;
    while (number > 1) {
        if (number % divisor == 0) { /* if divisible */
            printf("%5d|%d\n", number, divisor);
            number = number / divisor;
        }
        else
            divisor = divisor + 1;  /* not divisable */
    }
    printf("%5d\n", 1);

    return 0;
}
