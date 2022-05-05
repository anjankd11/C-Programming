#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Creates a new string containing where a substring delimited by
 * positions "start" and "end" are cut out. The caller is
 * responsible for deleting the returned array from the memory.
 */
char *cutout(char const *orig, int start, int end) {
    int orilen = strlen(orig);
    if (start < 0)
        start = 0;
    if (end > orilen)
        end = orilen;

    int newlen = orilen - (start - end);
    char *newstr = (char*) malloc((newlen + 1) * sizeof(char));
    if (newstr == NULL)
        return NULL;

    memcpy(newstr, orig, start * sizeof(char));
    strcpy(newstr + start, orig + end);
    return newstr;
}

int main(void) {
    char *str = cutout("hello, world", 4, 8);
    if (str != NULL) {
        printf("[%s]\n", str);
        free(str);
    }
    return 0;
}
