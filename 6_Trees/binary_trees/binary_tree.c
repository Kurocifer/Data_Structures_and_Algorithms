#include <stdlib.h>
#include <stdio.h>

#define OK 0
#define ERROR 1
#define LCHILD -1
#define RCHILD -2

struct bt_node {
    int data;
    struct bt_node *lchild;    /* left child node */
    struct bt_node *rchild;    /* right child node */   
};

struct bt_node *root = NULL;



/* BINARY TREE INSERTION FUNCTIONS */
struct bt_node *get_new_node(void)
{
    struct bt_node *new_node = malloc(sizeof(struct bt_node));

    if(new_node == NULL) {
        fprintf(stderr, "Error can't create new node\n");
        return NULL;
    }

    new_node->lchild = NULL;
    new_node->rchild = NULL;

    return new_node;
}

void bt_insertion(int new)
{
    struct bt_node *p, *q;

    if(root == NULL) {
        root = get_new_node();
        root->data = new;
        return;
    }

    p = root;

    while(p != NULL) {
        q = p;

        if(new < p->data)
            p = p->lchild;
        else
            p = p->rchild;
    }
    /* q now points to the parent of the new node */

    p = get_new_node();
    p->data = new;

    if(new < q->data)
        q->lchild = p;
    else
        q->rchild = p;

}    

/* END OF BINARY TREE INSERTION FUNCTIONS */

/* BINARY TREE DELETION */
 
 
int bt_delete(struct bt_node *pred, struct bt_node *node,
		int stat)
{
	struct bt_node *child;

	if(node == NULL)
		return ERROR;

	if(pred == NULL) {
		root = node->rchild;
		child = node->lchild;
		bt_freenode(node);
		return (bt_insert2(child));
	}

	if(node->lchild == NULL && node->rchild == NULL)
		child = NULL;
	else if(node->lchild == NULL)
		child = node->rchild;
	else if(node->rchild == NULL)
		child = node->lchild;
	else if(node->lchild->rchild == NULL) {
		child = node->lchild;
		node->lchild->rchild = node->rchild;
	}
	else if(node->rchild->lchild == NULL) {
		child = node->rchild;
		node->rchild->lchild = node->lchild;
	}
	else {
		child = node->rchild;
		if(stat == LCHILD)
			pred->lchild = node->rchild;
		else
			pred->rchild = node->rchild;
		free(node);
		return (bt_insert2(node->lchild));
	}

	if(stat == LCHILD )
		pred->lchild = child;
	else
		pred->rchild = child;
	bt_freenode(node);
	
	return OK;
}
/* END OF BINARY TREE DELETION FUNCTIONS

/* BINARY TREE TRAVERSAL TECHNIQUES */

/* inorder traversal */
void inorder(struct bt_node *node)
{
    if(node != NULL) {
        inorder(node->lchild);
        printf("%d", node->data); /* The visit*/
        inorder(node->rchild);
    }
}

/* preordrer traversal */
void preorder(struct bt_node *node)
{
    if(node != NULL) {
        printf("%d", node->data);
        preorder(node->lchild);
        preorder(node->rchild);
    }
}

/* postorder traversal */
void postorder(struct bt_node *node)
{
    if(node != NULL) {
        preorder(node->lchild);
        preorder(node->rchild);
        printf("%d", node->data);
    }
}

/* END OF BINARY TREES TRAVERSAL TECHNIQUES */

/* bt_copy: makes a copy of a binary tree */
struct bt_node *bt_copy(struct bt_node *treeptr)
{
    struct bt_node *new;

    if(treeptr == NULL)
        return NULL;
    
    new = get_new_node();
    new->data = treeptr->data;
    new->lchild = bt_tree(treeptr->lchild);
    new->rchild = bt_tree(treeptr->rchild);

    return new;
}

int main(void) {
    int i;

    for(i = 0; i < 10; i++) {
        bt_insertion(i);
    }

    inorder(root);
    printf("\n");
    preorder(root);

    return 0;
}
