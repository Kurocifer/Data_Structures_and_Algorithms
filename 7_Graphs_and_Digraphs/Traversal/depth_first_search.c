#include <stdio.h>

#define VISITED 1
#define MAX_NODES 100

struct adj_node {
    int vertex;
    struct adj_node *next;
};

struct adj_list {
    int tag;    /* set to visited if a vertex has been visited */
    struct adj_node *adj;
}aist[MAX_NODES];

struct adj_node *getnode();

void dfs(int vertex)
{
    struct adj_node *ptr;

    printf("%d ", vertex);
    alist[vertex].tag = VISITED;

    ptr = alist[vertex];

    while(ptr != NULL) {
        if( alist[ptr->vertex].tag != VISITED )
            dfs(ptr->vertex);

        ptr = ptr->next;
    }
    printf("\n");
}