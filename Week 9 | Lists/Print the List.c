#include <stdlib.h>

typedef struct ListEl {
    int data;
    struct ListEl *nxt;
} ListEl;


/* creates a new list from the array elements */
ListEl *list_build(void) {
    int values[] = { 8, 14, 13, 17, 1, 19, 16, 5, 3, 11, 2,
                     15, 9, 10, 6, 22, 4, 7, 18, 27, -1 };
    ListEl *lis = NULL;

    int i;
    for (i = 0; values[i] != -1; ++i) {
        ListEl *u;
        u = (ListEl*) malloc(sizeof(ListEl));
        u->nxt = lis;
        u->data = values[i];
        lis = u;
    }
    return lis;
}


int main(void) {
    ListEl *head;

    head = list_build();

    //....

    return 0;
}
