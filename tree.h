#ifndef TREE_H
#define TREE_H

typedef struct tree tree;

/**
 * Create an empty binary tree and return a pointer to memory address where the tree is stored.
 * @param assign: a function to copy a value from an address to another;
 * @param cmp: a function to compare two values;
 * @return: a pointer to a binary tree.
 */
tree *tree_create(void (*assign)(void *, void *), int (*cmp)(void *, void *), size_t elem_size);

/**
 * Destroy the binary tree and all elements contained on it.
 * @param pt: a pointer to a memory addres where the tree is stored.
 */
void *tree_destroy(tree **pt);

#endif // TREE_H