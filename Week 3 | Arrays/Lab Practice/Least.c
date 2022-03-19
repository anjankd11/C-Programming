/*Write a program that creates an array of ten elements!
Assign initial values to the array elements, too! (So you do not need to read them one by one.) Print the array to the screen!
Modify your program to print the corresponding index values, too!
Extend your program to find and print the least element of the array.
(Test it for three cases: when the least number is the first element of the array;
when it is the last; when it is somewhere in between them!) Print the array in such manner
that a special mark is printed at the least element. */

#include <stdio.h>

int main(void) {
    int array[10] = { 25, 69, 54, 8, 77, 6, 29, 10, 3, 98 };

    /* Printing */
    printf("Array: ");
    for (int i = 0; i < 10; i = i + 1)
        printf(" %d", array[i]);
    printf("\n\n");

    /* Printing */
    printf("The array:");
    for (int i = 0; i < 10; i = i + 1)
        printf(" [%d]=%d", i, array[i]);
    printf("\n\n");

    /* Minimum finding */
    int minloc = 0;
    for (int i = 1; i < 10; i = i + 1)
        if (array[i] < array[minloc])
            minloc = i;
    printf("The least: %d\n", array[minloc]);
    printf("Index of the least: %d\n", minloc);

    /* Marked printing */
    printf("Marked: ");
    for (int i = 0; i < 10; i = i + 1) {
        printf(" %d", array[i]);
        if (i == minloc)
            printf("[MIN]");
    }
    printf("\n");

    return 0;
}
