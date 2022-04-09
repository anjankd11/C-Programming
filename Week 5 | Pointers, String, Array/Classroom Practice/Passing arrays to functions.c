#include <stdio.h>

void separate(int *in, int in_len, int *out_even, int *out_odd, int *out_even_len) {
    int i_even = 0, i_odd = 0;
    for (int i = 0; i != in_len; ++i) {
        if (in[i] % 2 == 0) {
            out_even[i_even++] = in[i];
        } else {
            out_odd[i_odd++] = in[i];
        }
    }
    *out_even_len = i_even;
}

void array_print(int *in, int in_len) {
    for (int i = 0; i != in_len; ++i)
        printf("%d, ", in[i]);
    printf("\n");
}

int main(void) {
    int numbers[10] = { 1, 7, 2, 6, 9, 3, 4, 5, 9, 1 };
    int even[10], odd[10];
    int even_len, odd_len;

    separate(numbers, 10, even, odd, &even_len);
    odd_len = 10 - even_len;

    printf("Even numbers:\n");
    array_print(even, even_len);
    printf("Odd numbers:\n");
    array_print(odd, odd_len);

    return 0;
}
