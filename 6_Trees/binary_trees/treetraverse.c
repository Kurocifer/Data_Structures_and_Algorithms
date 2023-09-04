struct bt_node {
    int data;
    struct bt_node *lchild;    /* left child node */
    struct bt_node *rchild;    /* right child node */   
};

/* inorder traversal */
void inorder(struct bt_node *node)
{
    if(node != NULL) {
        inorder(node->lchild);
        print_node(node->data); /* The visit*/
        inorder(node->rchild);
    }
}

/* preorder traversal */
void preorder(struct bt_node *node)
    }
}