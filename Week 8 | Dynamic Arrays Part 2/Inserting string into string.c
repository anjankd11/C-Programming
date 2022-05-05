#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Insters "what" into "target" at position "index"
 * Returs with the dynamically allocated result string
 * The caller has to free the returned string
 */
char *insertstring(char const *orig, int index, char const *what) {
    int newlen = strlen(orig) + strlen(what);

    char *newstr = (char*) malloc((newlen + 1) * sizeof(char));
    if (newstr == NULL)
        return NULL;

    newstr[0] = '\0';
    strncat(newstr, orig, index);
    strcat(newstr, what);
    strcat(newstr, orig + index);
    return newstr;
}

int main(void) {
    char *str = insertstring("hello!", 5, ", world");
    if (str != NULL) {
        printf("[%s]\n", str);
        free(str);
    }
    return 0;
}
