/*Stammering (or stuttering) is a speech disorder when syllables (usually the first one in the words)
are unintentionally repeated. Look at the following ahartihifihicihiahal stahammehereher cohodehe (artificial stammerer code)
#include <stdio.h>

int main(void) {
    char c;
    while (scanf("%c", &c) == 1) {
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            printf("%ch%c", c, c);
        else
            printf("%c", c);
    }

    return 0;
}
Write a function to tell vowels from other letters. Modify the program above to use this function in main(). */

#include <stdio.h>
#include <stdbool.h>

/* Returns true if the function parameter is a vowel. */
bool vowel(char c) {
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

int main() {
    char c;
    while (scanf("%c", &c) != EOF)
        if (vowel(c))
            printf("%cv%c", c, c);
        else
            printf("%c", c);

    return 0;
}
