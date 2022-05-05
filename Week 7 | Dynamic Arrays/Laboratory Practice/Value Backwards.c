/*Write a program, that first asks the user the number of real values to read;
then it reads the values into a dynamically allocated array.
 At last the program should print the array backwards, and release the allocated memory! */

 #include <stdio.h>
#include <stdlib.h>

int main(void) {
    int cnt;
    printf("How many numbers?\n");
    scanf("%d", &cnt);

    double *numbers = (double*) malloc(sizeof(double) * cnt); // !
    if (numbers == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d numbers:\n", cnt);
    for (int i = 0; i < cnt; ++i) {
        scanf("%lf", &numbers[i]);                           // !
    }

    for (int i = cnt-1; i >= 0; --i) {
        printf("%g\n", numbers[i]);
    }

    free(numbers);                                           // !

    return 0;
}
