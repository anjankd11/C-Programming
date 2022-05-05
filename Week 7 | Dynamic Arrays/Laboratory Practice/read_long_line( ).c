/*Modify the previous program so that you put the reading of the line into
a separate function! The return value should be the address of the array containing the text read in.
Test this program. */

#include <stdio.h>
#include <stdlib.h>

char *read_long_line() {
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

    return line;
}

int main(void) {
    printf("Enter an arbitrary long line!\n");
    char *line = read_long_line();
    printf("[%s]\n", line);
    free(line);

    return 0;
}
