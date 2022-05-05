/*We have solved this task before. We have a string, and the
task is to remove all space characters from it.
In our previous solution we have removed the spaces in-place,
the input array was modified and it stored the output when the function finished. L
Let us solve it differently, such a way, that the function creates and returns a brand new string instead.

Write a simple C program to demonstrate the usage of the function. */

#include <stdio.h>
#include <stdlib.h>

char *removespaces(char const *inp) {
    int nonspace = 0;
    for (int i = 0; inp[i] != '\0'; ++i)
        if (inp[i] != ' ')
            nonspace += 1;

    char *str = (char*) malloc(sizeof(char) * (nonspace+1));
    if (str == NULL)
        return NULL;    /* :( */

    int j = 0;
    for (int i = 0; inp[i] != '\0'; ++i)
        if (inp[i] != ' ')
            str[j++] = inp[i];
    str[j] = '\0';

    return str;
}

int main(void) {
    char *nospaces = removespaces("hello word apple tree");
    if (nospaces == NULL) {
        printf("there was an error, no space-free string is available");
    } else {
        printf("%s", nospaces);
        free(nospaces);
    }

    return 0;
}
