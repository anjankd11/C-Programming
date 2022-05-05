#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Creates a new string from "orig" consisting of characters
 * between positions start and end. The caller is responsible
 * to release the memory behind the result of the function.
 */
char *substring(char const *orig, int start, int end) {
    int orilen = strlen(orig);
    if (start < 0)
        start = 0;
    if (end > orilen)
        end = orilen;

    int newlen = end - start;
    char *newstr = (char*) malloc((newlen + 1) * sizeof(char));
    if (newstr == NULL)
        return NULL;

    memcpy(newstr, orig + start, newlen * sizeof(char));
    newstr[newlen] = '\0';
    return newstr;
}

int main(void) {
    char *str = substring("hello, world", 3, 9);
    if (str != NULL) {
        printf("[%s]\n", str);
        free(str);
    }
    return 0;
}
