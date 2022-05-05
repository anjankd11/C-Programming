#include <stdlib.h>
#include <stdio.h>


/* an element of the list: */
typedef struct ListEl {
    int data;              /* The data to store */
    struct ListEl *nxt;    /* Pointer to the next list element */
} ListEl;


/* Printing the list */
void list_print(ListEl *head) {
    ListEl *p;
    for (p = head; p != NULL; p = p->nxt)
        printf("%d ", p->data);
    printf("\n");
}

/* Releasing a list */
void list_free(ListEl *head) {
    ListEl *p = head;
    /* Traversing the list */
    while (p != NULL) {
        /* Just writing free(p); is wrong, the rest of the list would be lost */
        /* hence p=p->nxt; would be invalid */
        ListEl *tmp = p->nxt; /* Store the pointer to the rest of the list */
        free(p); /* Now we can delete the current element */
        p = tmp; /* Keep releasing the list from the next element on */
    }
}

/* Inserting a new element to the head of the list */
ListEl *list_insert_athead(ListEl *head, int what) {
    ListEl *newel = (ListEl *) malloc(sizeof(ListEl)); /* New element */
    newel->data = what; /* Copy data to store to the list element */
    newel->nxt  = head; /* After the new element goes the rest of the list (even if it is empty) */
    return newel; /* The new element will be the new head of the list */
}

/* Inserting a new element to the end of the list */
ListEl *list_insert_atend(ListEl *head, int what) {
    ListEl *newel = (ListEl *) malloc(sizeof(ListEl)); /* New element */

    newel->data = what; /* Copy data to store to the list element */
    newel->nxt  = NULL; /* This will be the last element of the list, next pointer is NULL */
    if (head == NULL) {
        return newel; /* If the list was empty, the new element is the head of the list */
    } else {
        ListEl *p = head; /* Walk to the end of the list */
        while (p->nxt != NULL) p = p->nxt;
        p->nxt = newel; /* ... and add the new element to the chain */
        return head; /* The head of the list did not change in this case */
    }
}

/* Return length of the list */
int list_length(ListEl *head) {
    /* Traversing the list and counting the number of elements */
    int len = 0;
    ListEl *p = head;
    while (p != NULL) {
        len++;
        p = p->nxt;
    }
    return len;
}

/* Searching for an element in the list */
ListEl *list_search(ListEl *head, int what) {
    ListEl *p;
    for (p = head; p != NULL; p = p->nxt)
        if (p->data == what)
            return p;
    return NULL;
}

/* The main program */
int main(void) {
    ListEl *head = NULL;

    head = list_insert_atend(head, 66);
    head = list_insert_athead(head, 55);
    head = list_insert_atend(head, 77);
    head = list_insert_athead(head, 44);
    head = list_insert_athead(head, 33);
    head = list_insert_athead(head, 22);
    head = list_insert_athead(head, 11);
    list_print(head);
    printf("\nLength: %d\n", list_length(head));

    ListEl *hit = list_search(head, 44);
    if (hit != NULL)
        printf("%d\n", hit->data);
    else
        printf("no such data in the list\n");

    list_free(head);

    return 0;
}
