//How many different ways can a path of given length be paved if we have stone
//elements of 1 and of 2 meters? For example if the path is 3 meters long then there are three cases: 1+1+1, 1+2, 2+1.



#include <stdio.h>

/**
 * Returns the number os different ways a path of
 * <len> meters can be paved with 1 and 2 meter stones.
 */
int pave(int len) {
    if (len == 0)
        return 1;   /* 1 way */
    if (len < 0)
        return 0;   /* impossible */

    return pave(len - 1) + pave(len - 2);
}

int main() {
    int n;
    printf("len?\n");
    scanf("%d", &n);

    printf("%d ways possible.\n", pave(n));
}
