#include <stdio.h>

int main(void) {
    int height;
    printf("Enter the height of the triangle: ");
    scanf("%d", &height);

    /* loop for the subsequent lines */
    for (int row = 1; row <= height; row = row+1) {
        /* printing the leading space characters */
        for (int x = 1; x <= height-row; x = x+1)
            printf(" ");
        /* printing the letter "o"-s */
        for (int x = 1; x <= row*2-1; x = x+1)
            printf("o");
        /* end of the current row, go to the next line */
        printf("\n");
    }

    return 0;
}
