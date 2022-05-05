/*Let us write a function that receives a double array and returns a new,
dynamically allocated array with the elements smaller than the average!
The function should return the array and its size through the parameter list, as pointers.
The return value itself should be true if the operation was successful and false if not.

Write a program to demonstrate how to use the function!*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int separate(double *source, int srclen, double **target, int *trglen) {
    /* calculating the average */
    double sum = 0;
    for (int i = 0; i < srclen; ++i)
        sum += source[i];
    double average = sum/srclen;

    /* determining the length of the target array */
    int cnt = 0;
    for (int i = 0; i < srclen; ++i)
        if (source[i] < average)
            ++cnt;

    double *newarr = (double *) malloc(sizeof(double)*cnt);
    if (newarr == NULL)
        return 0;

    int index = 0;
    for (int i = 0; i < srclen; ++i)
        if (source[i] < average) {
            newarr[index] = source[i];
            ++index;
        }

    *target = newarr;
    *trglen = cnt;
    return 1;
}


int main(void) {
    double numbers[5] = {3.4, 8.5, 4.6, 9.1, 1.2};

    double *narr;
    int nlen;
    separate(numbers, 5, &narr, &nlen);
    for (int i = 0; i < nlen; ++i)
        printf("%f ", narr[i]);
    free(narr);

    return 0;
}
