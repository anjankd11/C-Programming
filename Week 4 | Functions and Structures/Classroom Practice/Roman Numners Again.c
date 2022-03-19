/*We considered values from big to small order. Like this:
if (num >= 5) { printf("V"); num -= 5; }
if (num >= 4) { printf("IV"); num -= 4; }
while (num >= 1) { printf("I"); num -= 1; }
A closer look at the problem shows that all conditional statements can be replaced by a while loop.
There was an if num>=5 conditional, which can be false or true resulting in 0 or 1 time execution – a while loop produces exactly the same behaviour.
The modified code will look like this:
…
while (num >= 5) { printf("V"); num -= 5; }
while (num >= 4) { printf("IV"); num -= 4; }
while (num >= 1) { printf("I"); num -= 1; }
…
This is a pattern that can easily be turned into a loop. Write the program this way! */

#include <stdio.h >

int main(void) {
    typedef struct Roman {
        char roman[5];
        int value;
    } Roman;
    Roman digits[] = {
        { "XC", 90 },
        { "L", 50 },
        { "XL", 40 },
        { "X", 10 },
        { "IX", 9 },
        { "V", 5 },
        { "IV", 4 },
        { "I", 1 },
        { "", 0 }      /* terminator of the array */
    };
    int num;

    printf("Enter the number: ");
    scanf("%d", &num);
    if (num < 1 || num > 99)
        printf("Wrong value. Must be between 1 and 99.\n");
    else {
        int i = 0;
        while (digits[i].value > 0) {
            while (num >= digits[i].value) {
                printf("%s", digits[i].roman);
                num -= digits[i].value;
            }
            ++i;  /* next roman digit */
        }

        printf("\n");
    }

    return 0;
}
