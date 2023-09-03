struct node {
    /* some data */
    struct node *next;
};

/* list reversal */
struct node *reverse(struct node *headlist)
{
    struct node *cur, *prev, *tmp;

    for(prev = NULL, cur = headlist; cur != NULL; cur = cur->next) {
        tmp = prev;
        prev = cur;
        prev->next = tmp;
    }

    return prev;    /* new head of list */
}

