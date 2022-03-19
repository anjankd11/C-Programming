/*Write a program that contains an array of 10 elements initialized by values of your choice.
Shift all elements in the array towards the beginning of the array by one cell.
The first element should go into the last cell (you may call this process rotation ).
Repeat the shifting (rotation) process 10 times, printing the array after each step.
Your output should be similar to the one shown on the right side. */

#include <stdio.h>

int main(void) {
    int array[10] = {25, 69, 54, 8, 77, 6, 29, 10, 3, 98};

    /* Printing and shifting 10 times */
    for (int j = 0; j < 10; j = j + 1) {
        /* Printing */
        for (int i = 0; i < 10; i = i + 1)
            printf("%d ", array[i]);
        printf("\n");

        /* Shifting */
        int tmp = array[0]; /* Saving the first element */
        for (int i = 0; i < 9; i = i + 1)
            array[i] = array[i+1]; /* Shifting */
        array[9] = tmp; /* Put the saved element to the last position */
    }

    return 0;
}
