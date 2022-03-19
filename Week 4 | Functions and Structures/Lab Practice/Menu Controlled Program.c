/*Create a simple menu controlled program!
The program stores a number with an initial value of n = 1.
Then the program should print the actual value of n and the menu below.
After the user selects a menu item (scanf()) the program should do ton
whatever the user requested and print the value of n and the menu!
These must be repeated as long as the user chooses anything but the
Exit menu option! Use switch() and post-testing do ... while() loop.

printf("0. Restore the initial value (n = 1)\n"
       "1. Add 1\n"
       "2. Negate the number (+/-)\n"
       "3. Multiple by 2\n"
       "9. Exit\n");
Realize each operation in a (tiny) function that receives the value
of n as a parameter and returns the modified value!
Your main() can only call these functions to change the value of n. */




#include <stdio.h>

int reset() {
    return 1;
}

int increment(int a) {
    return a+1;
}

int invert(int a) {
    return -a;
}

int duplicate(int a) {
    return 2*a;
}

int main() {
    int menuselection;
    int a = reset();
    do {
        printf("a = %d\n\n", a);
        printf(
            "0. Re-setting the variable (a = 1)\n"
            "1. Increment by 1\n"
            "2. Invert the sign\n"
            "3. Multiply by 2\n"
            "9. Exit\n"
            "? ");
        scanf("%d", &menuselection);
        switch (menuselection) {
            case 0: a = reset(); break;
            case 1: a = increment(a); break;
            case 2: a = invert(a); break;
            case 3: a = duplicate(a); break;
            case 9: /* nothing, we are going to exit */ break;
            default: printf("HEY!\n"); break;
        }
        printf("\n");          /* cosmetic line break */
    } while (menuselection != 9);

    return 0;
}

