/*Create a function that receives an array of integers as parameter,
and one integer value that has to be found in the array! Return the index
of the element if the value was found, or return −1, if it was not.
(If the value occurs multiple times in the array, it is up to you which index you return.)

Print the array with the indices to check the result of your function.
Print the index returned by the function, or the text „not found”! */

#include <stdio.h>

int search(int *array, int n_elem, int to_find) {
    int i;
    for (i = 0; i != n_elem; ++i)
        if (array[i] == to_find)
            return i;
    return -1;
}

int *search_ptr(int *array, int n_elem, int to_find) {
    int i;
    for (i = 0; i != n_elem; ++i)
        if (array[i] == to_find)
            return array+i;
    return NULL;
}

int *search_ptr_arithm(int *array, int n_elem, int to_find) {
    int *p;
    for (p = array; p != array+n_elem; ++p)
        if (*p == to_find)
            return p;
    return NULL;
}

int main(void) {
    int values[10] = { 5, 8, 3, 6, 9, -2, 4, 6, 7, 1 };

    int to_find = -2;

    int index = search(values, 10, to_find);
    if (index != -1) {
        printf("%d has an index of: %d\n", to_find, index);
    } else {
        printf("%d not found\n", to_find);
    }

    int *p1 = search_ptr(values, 10, to_find);
    if (p1 != NULL) {
        printf("%d is at the memory address: %p, has the index: %ld\n", to_find, p1, p1-values);
    } else {
        printf("%d not found\n", to_find);
    }

    int *p2 = search_ptr_arithm(values, 10, to_find);
    if (p2 != NULL) {
        printf("%d is at the memory address: %p, has the index: %ld\n", to_find, p2, p2-values);
    } else {
        printf("%d not found\n", to_find);
    }
}
