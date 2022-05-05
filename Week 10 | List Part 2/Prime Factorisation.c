/*Define a type to store prime factors (prime value, multiplicity) in a linked list!

Write a function that takes such a list as parameter and prints the prime factors in the following form: 2^2 * 3^1 * 5^1. (You may wish to write some code − that should be deleted later − to generate sample data for testing this function.)
Write a function that takes an integer parameter and returns the list of its prime factors (in growing order of the factors). It can be advantageous to keep track of the last element since we always insert at the end.
Write a function that takes two prime factor lists, and returns their GCD in a new list! You must find the common factors, and use the less multiplicity value in the result. (You can take advantage of the fact that each list contains factors in increasing order.)
Write a program that prints the prime factorization of the GCD of two numbers!*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Factor {
    int factor, mult;
    struct Factor *nxt;
} Factor;

void print(Factor *l) {
    Factor *iter;
    for (iter = l; iter != NULL; iter = iter->nxt) {
        printf("%d^%d", iter->factor, iter->mult);
        if (iter->nxt != NULL)
            printf(" * ");
    }
    printf("\n");
}

Factor *factorize(int n) {
    Factor *head = NULL;          /* empty list */
    Factor *last = NULL;
    int divisor = 2;
    while (n > 1) {
        int mult = 0;
        while (n % divisor == 0) {   /* while it divides  */
            n /= divisor;
            ++mult;                  /* divide and count */
        }
        if (mult > 0) {           /* if it is a divisor, insert it */
            Factor *n_e = (Factor *) malloc(sizeof(Factor));
            n_e->factor = divisor;
            n_e->mult = mult;
            n_e->nxt = NULL;
            if (head == NULL)
                head = n_e;
            else
                last->nxt = n_e;
            last = n_e;
        }
        divisor++;
    }
    return head;
}

int min(int a, int b) {
    return a < b ? a : b;
}

Factor *Gcd(Factor *one, Factor *other) {
    Factor *head = NULL;
    Factor *last = NULL;
    while (one != NULL && other != NULL) { /* while there can be common factors */
        if (one->factor == other->factor) {  /* equal factors? put into GCD! */
            Factor *n_e = (Factor *) malloc(sizeof(Factor));
            n_e->factor = one->factor;
            n_e->mult = min(one->mult, other->mult);
            n_e->nxt = NULL;
            if (head == NULL)
                head = n_e;
            else
                last->nxt = n_e;
            last = n_e;
            one = one->nxt;
            other = other->nxt;
        }
        else
        if (one->factor < other->factor) /* is one less that other? step in one */
            one = one->nxt;
        else
            other = other->nxt; /* not less, nor equal means greater: step other */

    }
    return head;
}

void destroy(Factor *l) {
    while (l != NULL) {
        Factor *nxt = l->nxt;
        free(l);
        l = nxt;
    }
}

int main(void) {
    Factor *one = factorize(360);
    Factor *other = factorize(80);
    Factor *gcd = Gcd(one, other);

    print(one);
    print(other);
    print(gcd);

    destroy(one);
    destroy(other);
    destroy(gcd);

    return 0;
}
