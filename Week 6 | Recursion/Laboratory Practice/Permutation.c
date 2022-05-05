//Print all permutations of a sequence of (different) numbers
//(stored in an array)! Like the permutations of 1 2 3 are: 123 132 213 231 312 321.

#include <stdio.h>

/* swaps index a and b values */
void swap(int* z, int a, int b) {
    int t = z[a];
    z[a] = z[b];
    z[b] = t;
}

void permute(int* z, int len, int start) {
    if (start == len-1) {
        /* nothing to permute */
        for(int i=0; i < len; ++i)
            printf("%d", z[i]);
        printf("  ");
    } else {
        /* first permute the rest of the array without swap
         * then in a loop swap index i and index start,
         * permute the rest and undo the swap to restore
         * the array in its original state. */
        permute(z, len, start+1);

        for (int i = start+1; i < len; ++i) {
            swap(z, start, i);    /* swap */
            permute(z, len, start+1);
            swap(z, start, i);    /* undo swap */
        }
    }
}

int main(void) {
    int s[4] = {1,2,3,4};
    permute(s, 4, 0);
    printf("\n");

    return 0;
}
