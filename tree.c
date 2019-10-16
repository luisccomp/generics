#include <stdlib.h>
#include "tree.h"

typedef struct node node;

struct tree {
    void (*assign)(void *, void *);
    int (*cmp)(void *, void *);
    size_t elem_size;
    int size;
    node *root;
};

struct node {
    void *item;
    node *left, *right;
};

/**
 * Create an empty binary tree and return a pointer to memory address where the tree is stored.
 * @param assign: a function to copy a value from an address to another;
 * @param cmp: a function to compare two values;
 * @return: a pointer to a binary tree.
 */
tree *tree_create(void (*assign)(void *, void *), int (*cmp)(void *, void *), size_t elem_size) {
    tree *t = (tree *) malloc(sizeof(struct tree));

    if (t != NULL) {
        t->assign = assign;
        t->cmp = cmp;
        t->elem_size = elem_size;
        t->size = 0;
        t->root = NULL;
    }

    return t;
}
