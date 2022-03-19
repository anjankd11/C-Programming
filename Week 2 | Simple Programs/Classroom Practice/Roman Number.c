#include <stdio.h>

int main(void) {
    int x;

    printf("Enter a number: ");
    scanf("%d", &x);
    if (x < 1)
        printf("The number must be positive.\n");
    else if (x > 99)
        printf("Only numbers less than 100 are supported.\n");
    else {
        if (x >= 90) { printf("XC"); x = x-90; }
        if (x >= 50) { printf("L"); x = x-50; }
        if (x >= 40) { printf("XL"); x = x-40; }
        while (x >= 10) { printf("X"); x = x-10; }
        if (x >= 9) { printf("IX"); x = x-9; }
        if (x >= 5) { printf("V"); x = x-5; }
        if (x >= 4) { printf("IV"); x = x-4; }
        while (x >= 1) { printf("I"); x = x-1; }
        printf("\n");
    }

    return 0;
}
