#include <stdlib.h>
#include "list.h"

typedef struct node node;

struct list {
    void (*assign) (void *, void *);
    int (*cmp) (void *, void *);
    size_t elem_size;
    int size;
    node *first;
    node *last;
};

struct node {
    void *item;
    node *next;
};

/**
 * Insert an item at the end of the list.
 * @param l: a linked list;
 * @param item: an item to be inserted;
 * @return: an error code indicating if insertion is successful or not.
 */
int list_append(list *l, void *item) {
    if (l == NULL)
        return LIST_NULL_PTR;

    node *n = (node *) malloc(sizeof(struct node));

    if (n == NULL)
        return LIST_OUT_OF_MEM;

    n->item = malloc(l->elem_size);

    if (n->item == NULL) {
        free(n);
        return LIST_OUT_OF_MEM;
    }

    l->assign(n->item, item);

    if (l->first == NULL) {
        n->next = NULL;
        l->first = n;
        l->last = l->first;
    }
    else {
        l->last->next = n;
        l->last = n;
        n->next = NULL;
    }

    ++ l->size;

    return SUCCESS;
}

/**
 * Check if list contains or not a given element.
 * @param l: a linked list;
 * @param item: an item;
 * @return: an error code or a idication if list contains or not the given element.
 */
int list_contains(list *l, void *item) {
    if (l == NULL)
        return LIST_NULL_PTR;

    node *curr = l->first;

    while (curr != NULL) {
        // Means the element exists on the list
        if (l->cmp(curr->item, item) == 0)
            return 1;
    }

    return 0;
}

/**
 * Create a new and empyt list and return a pointer to a memory address where
 * this list is stored.
 * @param assign: a pointer to a function that assugign a value to a memory
 * address;
 * @param cmp: a pointer to a function that compare two values;
 * @param elem_size: the size (in bytes) of every element on the list;
 * @return: a pointer to an empty linked list or NULL if allocation fails.
 */
list *list_create(void (*assign)(void *, void *), int (*cmp)(void *, void *), size_t elem_size) {
    list *l = (list *) malloc(sizeof(struct list));

    if (l != NULL) {
        l->assign = assign;
        l->cmp = cmp;
        l->elem_size = elem_size;
        l->size = 0;
        l->first = NULL;
        l->last = NULL;
    }

    return l;
}

/**
 * Destroy the linked list and its stored elements. After destroy everything,
 * this function will assign NULL to the pointer for futher uses.
 * @param l: a pointer to a linked list address.
 */
void list_destroy(list **pl) {
    list *l = *pl;

    if (l != NULL) {
        node *curr = l->first;

        while (curr != NULL) {
            node *prev = curr;
            curr = curr->next;
            free(prev->item);
            free(prev);
        }

        free(l);
        *pl = NULL;
    }
}

/**
 * Checks if a list is empty or not.
 * @param l: a linked list;
 * @return: an error code or an indication if list is empty or not.
 */
int list_empty(list *l) {
    if (l == NULL)
        return LIST_NULL_PTR;

    return (l->first == NULL);
}

/**
 * Get an especific element on a given position inside the list.
 * @param l: a linked list;
 * @param pos: the position of element;
 * @param item: a pointer to a variable where you want to store the given item;
 * @return: the function error code.
 */
int list_get(list *l, int pos, void **item) {
    if (l == NULL)
        return LIST_NULL_PTR;

    if (pos >= l->size)
        return LIST_OUT_OF_INDEX;

    int i = 0;
    node *curr = l->first;

    while (i < pos) {
        ++ i;
        curr = curr->next;
    }

    l->assign(*item, curr->item);

    return SUCCESS;
}

/**
 * Remove the first element of a list;
 * @param l: a linked list;
 * @param item: a pointer to a variable to store the removed item;
 * @return: function error code.
 */
int list_pop(list *l, void **item) {
    if (l == NULL)
        return LIST_NULL_PTR;

    if (l->first == NULL)
        return LIST_EMPTY;

    node *curr = l->first;
    l->assign(*item, curr->item);
    l->first = curr->next;
    free(curr->item);
    free(curr);
    -- l->size;

    return SUCCESS;
}

/**
 * Insert a new item on the top of the list.
 * @param l: a linked list;
 * @param item: an item to be inserted;
 * @return: return an error code indicating if operation was successful or not.
 */
int list_push(list *l, void *item) {
    if (l == NULL)
        return LIST_NULL_PTR;

    node *n = (node *) malloc(sizeof(struct node));

    if (n == NULL)
        return LIST_OUT_OF_MEM;

    n->item = malloc(l->elem_size);

    if (n->item == NULL) {
        free(n);
        return LIST_OUT_OF_MEM;
    }

    l->assign(n->item, item);

    // Check if list is empty or not
    if (l->first == NULL) {
        l->first = n;
        l->last = l->first;
        n->next = NULL;
    }
    else {
        n->next = l->first;
        l->first = n;
    }

    ++ l->size;

    return SUCCESS;
}

/**
 * Count the number of elements the current list contains.
 * @param l: a linked list;
 * @return: an error code or the size of the list.
 */
int list_size(list *l) {
    if (l == NULL)
        return LIST_NULL_PTR;

    return l->size;
}
