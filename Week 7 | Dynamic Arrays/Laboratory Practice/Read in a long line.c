/*The gets() function (reading a line of text) is very much unsafe:
an array must be used in the call, to store the text but the required
size of the array turns out after reading the whole line only.

The solution is very similar to the previous one but
the array stores chars instead of real values and the terminator
is a newline character instead of –1. We must pay special attention to one thing:
what is the content of the array when the string is empty?
How many elements are there in the array?

Read in a line of arbitrary length and print it again! */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Enter an arbitrary long line!\n");
    int cnt = 0;
    char *line = (char*) malloc(sizeof(char) * 1);
    line[0] = '\0';
    char newchar;
    while (scanf("%c", &newchar) == 1 && newchar != '\n') {
        /* array extension */
        char *newarr = (char*) malloc(sizeof(char) * (cnt+1+1));
        for (int i = 0; i < cnt; ++i)
            newarr[i] = line[i];
        newarr[cnt] = newchar;
        newarr[cnt+1] = '\0';
        free(line);
        line = newarr;
        ++cnt;
    }

    printf("[%s]\n", line);

    free(line);

    return 0;
}
