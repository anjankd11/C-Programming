/*It is a common task to remove leading and trailing spaces from a string.
This function is often called trim().

Write a function that removes the spaces at the beginning and at the end
of the string (other spaces must stay)! For example if the original string
is "  Hi, what's up?   ", then the new string should be "Hi, what's up?".
 The function should take two parameters: a source array (containing the original string)
  and a destination array (to put the trimmed string into). */

  #include <stdio.h>

void trim(char *source, char *dest) {
    int begin = 0, end = 0;

    /* Jump spaces at the beginning */
    while (source[begin] != '\0' && source[begin] == ' ')
        begin++;
    /* Where is the end od the string? Then go back and cut the trailing spaces */
    while (source[end] != '\0')
        end++;
    end--;
    while (end >= 0 && source[end] == ' ')
        end--;
    /* Copy to the beginning and close */
    int i;
    for (i = 0; i <= end-begin; i++)
        dest[i] = source[begin+i];
    dest[i] = '\0';
}
int main(void) {
    char s1[100] = "      Hey what's up?   ";
    char s2[100];

    trim(s1, s2);
    printf("[%s] [%s]\n", s1, s2);

    return 0;
}
