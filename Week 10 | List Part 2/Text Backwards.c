#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Stack {
    char one_char;
    struct Stack *deeper;
} Stack;


void push(Stack **s, char c) {
    Stack *n_e = (Stack *) malloc(sizeof(Stack));
    n_e->one_char = c;
    n_e->deeper = *s;            /* the top element sinks deeper */
    *s = n_e;                    /* this is the top from now on */
}


char pop(Stack **s) {
    Stack *first = *s;            /* the first will be removed */
    char data = first->one_char;  /* save the char from it */
    *s = first->deeper;           /* second raises to be first */
    free(first);
    return data;
}


bool is_empty(Stack **s) {
    return *s == NULL;
}


int main(void) {
    Stack *s = NULL;

    printf("Write text of arbitrary length terminated by end of file!\n");
    char c;
    while (scanf("%c", &c) == 1)
        push(&s, c);

    printf("Your text backwards:\n");
    while (!is_empty(&s))
        printf("%c", pop(&s));

    return 0;
}
