#include <stdio.h>

void removespaces(char *t) {
    /* go through all of the characters */
    /* "from" increases in every iteration, "to" increases only if needed */
    int to = 0;
    for (int from = 0; t[from] != '\0'; ++from) {
        /* if not a space, copy it */
        if (t[from] != ' ') {
            t[to] = t[from];
            to++;
        }
    }
    t[to] = '\0';  /* terminating zero */
}

int main(void) {
    char hello[] = "H e l l o, world!";

    removespaces(hello);
    printf("Without spaces: [%s]\n", hello);

    return 0;
}
