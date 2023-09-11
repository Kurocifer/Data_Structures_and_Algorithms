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
}alist[MAX_NODES];

struct adj_node *getnode();


/**
 * dfs: depth fist search algorithm for graph travesal
*/
void dfs(int vertex)
{
    struct adj_node *ptr;

    printf("%d ", vertex);
    alist[vertex].tag = VISITED;

    ptr = alist[vertex];

    for(ptr = alist[vertex]; ptr != NULL; ptr = ptr->next) {

        if( alist[ptr->vertex].tag != VISITED )
            dfs(ptr->vertex);
    }
    printf("\n");
}

/**
 * bfs: Breadth first search traversal.
*/
void bfs(void)
{
    int node;
    struct adj_node *tmp;

    /* put first element on queue */
    addqueue(0);
    alist[0].tag = VISITED;

    /* Begin BFS traversal */
    while((node = dequeue()) != QUEUE_EMPTY) {
        printf("%d ", node);

        /* Add adjecent nodes to queue */
        for(tmp = alist[node].adj; tmp != NULL; tmp = tmp->next) {

            if(alist[tmp->vertex].tag != VISITED) {
                addqueue(tmp->vertex);
                alist[tmp->vertex].tag = VISITED;
            }
        }
    }
}

/**
 * conn_grapsh: checks if the grapsh is connected
*/
bool conn_graph(void)
{
    int i;

    /* initialize the tag field */
    for(i = 0; i < MAX_NODES; i++) 
        alist[i].tag = NOT_VISITED;

    dfs(0);

    for(i = 0; i < MAX_NODES; i++){
        if(alist[i].tag != VISITED)
            return false;
    }

    return true;
}