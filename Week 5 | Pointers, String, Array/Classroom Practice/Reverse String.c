#include <stdio.h>
#include <string.h>

void reverse_to_array(char *in, char *out) {
    /* find the position of the last valid character */
    int i = strlen(in) - 1;

    /* goes backwards and puts all the characters to the output array */
    int j = 0;
    while (i >= 0) {
        out[j] = in[i];
        ++j;
        --i;
    }

    /* closing the output string with a terminating zero value */
    out[j] = '\0';
}

void reverse_inplace(char *str) {
    /* determine the length of the string */
    int len = strlen(str);

    /* going till the middle */
    for (int i = 0; i != len/2; ++i) {
        /* str[i] <-> str[len-1-i] */
        char temp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }

    /* the terminating zero value remains where it was originally */
}

int main(void) {
    char first[] = "hello world!";

    char second[20];
    reverse_to_array(first, second);
    printf("[%s] [%s]\n", first, second);

    printf("[%s]\n", second);
    reverse_inplace(second);
    printf("[%s]\n", second);

    return 0;
}
