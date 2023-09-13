/* Minimal Spanning Tree data structure */
#define MAX_NODES 100

int s2list = -1;    /* Head ptr for v2 list */

struct nadj_list {
    int node;               /* ID of adjecent node */
    int weight;             /* Weight of incident edge */
    struct nadj_list *next; /* Pointer to next element */
};

struct mst_graph {
    int set;                /* S1, S2, or S3 */
    int s2link;             /* Points to next S2 node */
    int vlnode;             /* V1 node of an (E1, E2) edge */
    int weight;
    struct nadj_list *adj;  /* Weight of E1 or E2 edge */
}graph[ MAX_NODES];