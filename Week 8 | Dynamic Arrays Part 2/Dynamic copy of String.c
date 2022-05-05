#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Copies the string received as a parameter dynamically, and
   returns the pointer pointing to the copy. The allocated
   memory space must be released by the caller. */
char *copystring(char const *str) {
    /* calculate the length of the string */
    int length = strlen(str);

    /* allocate space, +1 for the terminating zero */
    char *newstr;
    newstr = (char*) malloc((length + 1) * sizeof(char));
    if (newstr == NULL)
        return NULL;    /* :( */

    /* copy the letters of the string, now there is enough space for that */
    strcpy(newstr, str);
    return newstr;
}


int main(void) {
    char *x;

    x = copystring("hello, dynamic word!");
    if (x != NULL) {
        printf("%s\n", x);
        free(x);
    }
    return 0;
}
