#include <stdlib.h>
#include <stdio.h>

#define NO 0
#define YES 1

#define BAL 0
#define LHIGH -1
#define RHIGH 1

struct avl_node {
    int data;
    int bal;
    struct avl_node *lchild;
    struct avl_node *rchild;
};

struct avl_node *root = NULL;

struct avl_node *avl_insert(struct avl_node *root, struct avl_node *new,
                            int *chg_hgt)
{
    if(root == NULL) {
        root = new;
        root->bal = BAL;
        root->lchild = NULL;
        root->rchild = NULL;
        *chg_hgt = YES;
    }

    else if(new->data < root->data) {
        root->lchild = avl_insert(root->lchild, new, chg_hgt);
        if(*chg_hgt) {
            if(root->bal == LHIGH)
                root = left_bal(root, chg_hgt);
            else if(root->bal == BAL)
                root->bal = LHIGH;
            else {
                root->bal = BAL;
                *chg_hgt = NO;
            }
        }
    }

    else {
        root->rchild = avl_insert(root->rchild, new, chg_hgt);
        if(*chg_hgt) {
            if(root->bal == LHIGH) {
                root->bal = BAL;
                *chg_hgt = NO;
            }
            else if(root->bal = BAL)
                root->BAL = LHIGH;
            else
                root = right_bal(root, chg_hgt);
        }
    }

    return root;
}

struct avl_node *right_bal(struct avl_node *node, int *chg_hgt)
{
    struct avl_node *rsub, *lsub;

    rsub = node->rchild;
    switch(rsub->bal) {
        case RHIGH:
            node->bal = BAL;
            rsub->bal = BAL;
            node = rotate_left(node) ;
            *chg_hgt = NO;
            break;
        
        case LHIGH:
            lsub = rsub->lchild;
            switch(lsub->bal) {
                case RHIGH:
                    node->bal = LHIGH;
                    rsub->bal = BAL;
                    break;
                
                case BAL:
                    node->bal = BAL;
                    rsub->bal = BAL;
                    break;

                case LHIGH:
                    node->bal = BAL;
                    rsub->bal = RHIGH;
                    break;
            }

            lsub->bal = BAL;
            node->rchild = rotate_right(node);
            node = rotate_left(node);
            *chg_hgt = NO;
            break;
    }

    return node;
}

struct avl_node *rotate_left(struct avl_node *node)
{
    struct avl_node *tmp;

    tmp = node->rchild;
    node->rchild = tmp->lchild;
    tmp->lchild = node;

    return tmp;
}

