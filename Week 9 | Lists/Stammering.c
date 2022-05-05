/* Inserts a zero and the list element each time
* an even number is found in the list
*/
void list_202(Number *list) {
    for (Number *iter = list; iter != NULL; iter = iter->nxt)
        if (iter->num % 2 == 0) {
            Number *newnum, *newzero;
            newnum = (Number*) malloc(sizeof(Number));
            newnum->num = iter->num;
            newnum->nxt = iter->nxt;
            newzero = (Number*) malloc(sizeof(Number));
            newzero->num = 0;
            newzero->nxt = newnum;
            iter->nxt = newzero;
            /* jump over the newly inserted elements */
            iter = iter->nxt->nxt;
        }
}
