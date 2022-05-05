/*Write a C function that counts how many characters
in a string meet a prescribed criterium (like lowercase letter,
digit, or punctuation mark). The criterium must be a parameter of the function! */

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool is_it_e(char c) {
    return c == 'E' || c == 'e';
}

bool my_isspace(char c) {
    return isspace(c);      /* char->int, int->bool conversion! */
}

bool my_islower(char c) {
    return islower(c);      /* char->int, int->bool conversion! */
}

/* The function for counting. */
/* The parameter "decide" is a pointer to a function that
takes a char parameter and returns a bool value */
int count_char(char *str, bool (*decide)(char)) {
    int darab = 0;
    for (int i = 0; str[i] != 0; ++i)
        if (decide(str[i]))
            darab++;
    return darab;
}

int main(void) {
    char text[] = "Joe earned 34 points for MT2 (but just eleven for MT1).";

    printf("The text: [%s]\n", text);
    printf("%d letters e or E \n", count_char(text, is_it_e));
    printf("%d space\n", count_char(text, my_isspace));
    printf("%d lowercase letters\n", count_char(text, my_islower));

    return 0;
}
