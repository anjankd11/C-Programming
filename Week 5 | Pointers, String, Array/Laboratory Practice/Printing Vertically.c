/*Write a program that reads in a word and prints it letter by letter vertically. */
#include <stdio.h>

int main(void) {
    char name[100];

    printf("Your first name:\n");
    scanf("%s", name);

    for (int i = 0; name[i] != '\0'; ++i)
        printf("%c\n", name[i]);

    return 0;
}
