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


struct node *lconcate( struct node *list1, struct node *list2 )
{
    struct node *p;

    /* Locate end of list */
    for(p = list1; p->next != NULL; p = p->next)
        ;

    /* Concatenate */
    p->next = list2;
    
    return list1;
}
