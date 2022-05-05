#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* from the previous task */
char *copystring(char const *str) {
    char *newstr = (char*) malloc((strlen(str) + 1) * sizeof(char));
    strcpy(newstr, str);
    return newstr;
}


/*
 * Appends "what" to "target". "target" must be allocated
 * dynamically. Returns with the address of the appended
 * string, and releases the memory behind "target"
 * Usage: x = stringcat(x, ...).
 * The caller is responsible to call free() for the
 * resulting string.
 */
char *stringcat(char *target, char const *what) {
    int newlen = strlen(target) + strlen(what);

    char *newstr = (char*) malloc((newlen + 1) * sizeof(char));
    if (newstr == NULL) return NULL;

    strcpy(newstr, target);
    strcat(newstr, what);

    free(target);
    return newstr;
}

int main(void) {
    char *x;
    x = (char*) malloc((strlen("apple")+1) * sizeof(char));
    strcpy(x, "apple");

    x = stringcat(x, "tree");
    if (x != NULL) {
        printf("%s\n", x);    // appletree
        free(x);
    }
    return 0;
}
