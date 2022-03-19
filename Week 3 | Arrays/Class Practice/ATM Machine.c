#include <stdio.h>

int main(void) {
    /* a 0 marks the end of the array */
    int banknotes[] = {20000, 10000, 5000, 2000, 1000, 500,
                    200, 100, 50, 20, 10, 5, 0};
    int howmuch;
    printf("How much is the change? ");
    scanf("%d", &howmuch);

    printf("The machine gives:\n");
    /* assume the banknotes are sorted in a descending order in the array.
       We start giving banknotes with higher values first. */
    for (int i = 0; banknotes[i] != 0; i += 1) {
        int pcs = howmuch/banknotes[i];
        if (pcs > 0) {
            printf("%d pcs %d Ft banknote.\n", pcs, banknotes[i]);
            /* Multiplying back by "pcs" we have the amount given out so far. */
            howmuch -= pcs*banknotes[i];
        }
    }
    if (howmuch != 0)
        printf("There is no such small coin/banknote: %d Ft\n", howmuch);
    return 0;
}
