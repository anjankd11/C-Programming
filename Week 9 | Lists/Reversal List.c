/* Reverses a linked list and
    * returns the pointer to the head of the reversed one.
    * Attention: the original list will be gone! The function uses
    * the elements of the original list to build the reversed one.
    * Usage:
    *   numbers = list_reverse(numbers);
    */
Number *list_reverse(Number *list) {
    Number *original = list;
    Number *reversed = NULL;

    while (original != NULL) {
        Number *relinked = original, *next = original->nxt;
        relinked->nxt = reversed;    /* add to the reversed */ /* 1 */
        reversed = relinked;                                   /* 2 */
        original = next;             /* take next from orig.*/ /* 3 */
    }

    return reversed;
}
