/* Write a program that reads a value from the user and draws a line built of + and − symbols. The number of the − characters should be equal to the entered value. */ 

#include <stdio.h>

int main(void){
    int length;
    printf("Length of the line: \n");
    scanf("%d", &length);  /* asking the user to enter the length */

    printf("+");  /* + sign at the beginning of the line */
    for (int i = 0; i < length; i = i+1)  /* A loop printing the - signs */
        printf("-");
    printf("+");  /* + sign at the end of the line */

    return 0;
}
