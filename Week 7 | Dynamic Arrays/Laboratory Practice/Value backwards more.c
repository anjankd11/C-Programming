/*The specification is very similar to the previous task except the number of values is not known in advance.
 The sequence of values is terminated (like –1 terminates the sequence).
Where should this program differ from the previous one?
 Write this program that increases the size of the dynamic array by each reading of a real value! */

 #include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* reading the numbers */
    printf("Enter the numbers, terminated by -1!\n");
    int cnt = 0;
    double *numbers = NULL;
    double newnum;
    while (scanf("%lf", &newnum) == 1 && newnum != -1) {
        /* extend the array by one element */
        double *newarr = (double*) malloc(sizeof(double) * (cnt+1)); // 1
        for (int i = 0; i < cnt; ++i)
            newarr[i] = numbers[i]; // 2
        free(numbers); // 3
        numbers = newarr; // 4
        numbers[cnt] = newnum; // 5
        ++cnt;
    }

    for (int i = cnt-1; i >= 0; --i) {
        printf("%f\n", numbers[i]);
    }

    free(numbers);

    return 0;
}
