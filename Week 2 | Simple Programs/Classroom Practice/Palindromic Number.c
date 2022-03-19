#include <stdio.h>

int main(void) {
    for (int a = 1; a <= 9; a = a + 1)
        for (int b = 0; b <= 9; b = b + 1)
            printf("%d%d%d ", a, b, a);

    return 0;
}
