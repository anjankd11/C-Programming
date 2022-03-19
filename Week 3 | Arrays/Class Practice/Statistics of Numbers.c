/*Write a program that reads numbers from the standard input, as long as it is successful. Assume the numbers fall between 1 and 10. The program should count the occurrences of the numbers and print the result to the standard output in a tabular format as shown in the figure. */
#include <stdio.h>

int main(void) {
    int t[10];

    for (int i = 1; i <= 10; i += 1)        /* fill array with 0 */
        t[i-1] = 0;

    printf("Enter numbers between 1 and 10, then something that is not a number!\n");
    /* while we succeed to read the numbers from the input */
    int number;
    while (scanf("%d", &number) == 1) {       /* processing */
        if (number >= 1 && number <= 10)
            t[number-1] += 1;
        else
            printf("The numbers must be between 1 and 10!\n");
    }

    for (int i = 1; i <= 10; i += 1)        /* display the array */
        printf("%d: %d\n", i, t[i-1]);

    return 0;
}
