#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
    int value;
    struct treenode *left;
    struct treenode *right;
} treenode;

treenode *create_node(int value)
{
    treenode *new_node = malloc(sizeof(treenode));

    if(new_node == NULL)
        fprintf(stderr, "Malloc couldn't allocate memory for new node");
    else {
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->value = value;
    }

    return new_node;
}

void print_tabs(int num_tabs)
{
    for(int i = 0; i < num_tabs; i++)
        printf("\t");
}

void print_tree_rec(treenode *node, int level) 
{
    if(node == NULL) {
        print_tabs(level);
        printf("---<empty>---\n");
        return;
    }

    print_tabs(level);
    printf("value: %d\n", node->value);

    printf("---<left>---\n");
    print_tabs(level);
    print_tree_rec(node->left, level + 1);

    printf("---<right>---\n");
    print_tabs(level);
    print_tree_rec(node->right, level + 1);
}

int main(void)
{
    treenode *n1 = create_node(23);
    treenode *n2 = create_node(89);
    treenode *n3 = create_node(47);
    treenode *n4 = create_node(15);
    treenode *n5 = create_node(29);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    print_tree_rec(n1, 0);

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);

    return 0;
}


// 'Droid Sans Mono', 'monospace', monospace, 