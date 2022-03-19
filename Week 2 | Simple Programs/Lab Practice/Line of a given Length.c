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
