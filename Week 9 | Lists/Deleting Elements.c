while (list != NULL && strlen(list->word) == 4) {
    Word *todelete = list;
    list = todelete->nxt;
    free(todelete);
}
if (list != NULL) {
    Word *delayed = list;
    Word *iter = list->nxt;

    while (iter != NULL) {
        Word *next = iter->nxt;

        if (strlen(iter->word) == 4) {
            delayed->nxt = next;    /* 1 */
            free(iter);              /* 2 */
        } else
            delayed = iter;
        iter = next;                 /* 3 */
    }
}
