#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct node node;

struct list {
    int (*compare)(void *, void *);
    size_t elem_size;
    int size;
    node *head;
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
 * @return: an error code.
 */
int list_append(list *l, void *item) {
    if (l == NULL)
        return LIST_NULL_PTR;

    node *n = (node *) malloc(sizeof(struct node));

    if (n == NULL)
        return LIST_OUT_OF_MEMORY;

    n->item = malloc(l->elem_size);

    if (n->item == NULL) {
        free(n);
        return LIST_OUT_OF_MEMORY;
    }

    if (memcpy(n->item, item, l->elem_size) != n->item) {
        free(n->item);
        free(n);
        return LIST_COPY_ERROR;
    }

    if (l->head == NULL) {
        l->head = n;
        l->last = n;
        n->next = NULL;
    }
    else {
        l->last->next = n;
        l->last = n;
        n->next = NULL;
    }

    ++ l->size;
    
    return 0;
}

/**
 * Create an empty list and return the memory address where the list descriptor is.
 * If allocation tails, return a NULL pointer instead.
 * @param compare: a function that compare two elements on the list;
 * @param elem_size: the size of each element stored on the list;
 * @return: a memory address where the list descriptor is.
 */
list *list_create(int (*compare)(void *, void *), size_t elem_size) {
    list *l = (list *) malloc(sizeof(struct list));

    if (l != NULL) {
        l->compare = compare;
        l->elem_size = elem_size;
        l->size = 0;
        l->head = NULL;
        l->last = NULL;
    }

    return l;
}

/**
 * Destroy the linked list and every element stored on it. Also assign NULL as list's
 * memory address.
 * @param l_ptr: a pointer to a memory addres where the list descriptor is.
 */
void list_destroy(list **l_ptr) {
    if (*l_ptr != NULL) {
        node *curr = (*l_ptr)->head;

        while (curr != NULL) {
            node *prev = curr;
            curr = curr->next;
            free(prev->item);
            free(prev);
        }

        free(*l_ptr);
        *l_ptr = NULL;
    } 
}

/**
 * Get an element of a given position on the list.
 * @param l: a linked list;
 * @param pos: the position of element;
 * @param item: an address to a variable where the returned item will be stored;
 * @return: an error code.
 */
int list_get(list *l, int pos, void *item) {
    if (l == NULL)
        return LIST_NULL_PTR;

    if (pos < 0 || pos >= l->size)
        return LIST_INDEX_ERROR;

    int i = 0;
    node *curr = l->head;

    while (i ++ != pos)
        curr = curr->next;

    if (memcpy(item, curr->item, l->elem_size) != item)
        return LIST_COPY_ERROR;

    return 0;
}

/**
 * Remove an element from the top of the list.
 * @param l: a linked list;
 * @param item: an address to store the removed item;
 * @return: an error code.
 */
int list_pop(list *l, void *item) {
    if (l == NULL)
        return LIST_NULL_PTR;

    if (l->head == NULL)
        return LIST_EMPTY;

    node *curr = l->head;

    if (memcpy(item, curr->item, l->elem_size) != item)
        return LIST_COPY_ERROR;

    l->head = curr->next;
    free(curr->item);
    free(curr);
    -- l->size;

    /*int error_code = list_remove(l, 0, item);
    
    switch(error_code) {
        case LIST_INDEX_ERROR:
            return LIST_EMPTY;
        default:
            return error_code;
    }*/

    return 0;
}

/**
 * Insert an element at the top of the list.
 * @param l: a linked list;
 * @param item: an item to be inserted;
 * @return: an error code.
 */
int list_push(list *l, void *item) {
    if (l == NULL)
        return LIST_NULL_PTR;

    node *n = (node *) malloc(sizeof(struct node));

    if (n == NULL)
        return LIST_OUT_OF_MEMORY;

    n->item = malloc(l->elem_size);

    if (n->item == NULL) {
        free(n);

        return LIST_OUT_OF_MEMORY;
    }

    if (memcpy(n->item, item, l->elem_size) != n->item) {
        free(n->item);
        free(n);

        return LIST_COPY_ERROR;
    }

    if (l->head == NULL) {
        l->head = n;
        l->last = n;
        n->next = NULL;
    }
    else {
        n->next = l->head;
        l->head = n;
    }

    ++ l->size;

    return 0;
}

/**
 * Remove an item from a given position on the list.
 * @param l: a linked list;
 * @param pos: a position of an item to be removed;
 * @param item: an address of a variable to store the removed item;
 * @return: an error code.
 */
int list_remove(list *l, int pos, void *item) {
    if (l == NULL)
        return LIST_NULL_PTR;

    if (pos < 0 || pos >= l->size)
        return LIST_INDEX_ERROR;

    int i = 0;
    node *prev = NULL;
    node *curr = l->head;

    while (i ++ != pos) {
        prev = curr;
        curr = curr->next;
    }

    if (memcpy(item, curr->item, l->elem_size) != item)
        return LIST_COPY_ERROR;

    if (curr == l->head) {
        l->head = curr->next;
        free(curr->item);
        free(curr);
    }
    else {
        prev->next = curr->next;
        free(curr->item);
        free(curr);
    }

    -- l->size;

    return 0;
}

/**
 * Remove an specific item from the list.
 * @param l: a linked list;
 * @param item: an item to be removed;
 * @return: an error code.
 */
int list_remove_item(list *l, void *item) {
    if (l == NULL)
        return LIST_NULL_PTR;

    if (l->compare == NULL)
        return LIST_NULL_CMP_FUN;

    node *prev = NULL;
    node *curr = l->head;

    while (curr != NULL && l->compare(curr->item, item) != 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL) {
        if (curr == l->head) {
            l->head = curr->next;
            free(curr->item);
            free(curr);
        }
        else {
            prev->next = curr->next;
            free(curr->item);
            free(curr);
        }
    }
    else {
        return LIST_NOT_FOUND;
    }

    -- l->size;

    return 0;
}

/**
 * Count how many elements was inserted on the list until the present moment.
 * @param l: a linked list;
 * @return: the list size or an error code.
 */
int list_size(list *l) {
    if (l == NULL)
        return LIST_NULL_PTR;

    return l->size;
}
