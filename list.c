#include <stdlib.h>
#include "list.h"


typedef struct node node;

struct list {
    void (*assign)(void *, void *);
    int (*compare)(void *, void *);
    int size;
    node *head;
};

struct node {
    void *item;
    node *next;
};


int list_append(list *l, void *item, size_t size) {
    // Return NULL POINTER error code
    if (l == NULL)
        return -1;

    node *n = (node *) malloc(sizeof(struct node));

    // Return OUT OF MEMORY error code
    if (n == NULL)
        return -2;

    n->item = malloc(size);

    // Also return OUT OF MEMORY error code
    if (n->item == NULL)
        return -2;

    l->assign(n->item, item);

    if (l->head == NULL) {
        n->next = l->head;
        l->head = n;
    }
    else {
        node *curr = l->head;

        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = n;
        n->next = NULL;
    }

    ++ l->size;

    // Return SUCCESS code
    return 0;
}


list *list_create(void (*assign)(void *, void *), int (*compare)(void *, void *)) {
    list *l = (list *) malloc(sizeof(struct list));

    if (l != NULL) {
        l->assign = assign;
        l->compare = compare;
        l->size = 0;
        l->head = NULL;
    }

    return l;
}


void list_destroy(list *l) {
    if (l == NULL) {
        node *curr = l->head;

        while (curr != NULL) {
            node *prev = curr;
            curr = curr->next;
            // Destroy node and its content
            free(prev->item);
            free(prev);
        }

        // Destroy the list itself
        free(l);
    }
}


void list_get(list *l, int pos, void **item) {
    // Return NULL POINTER error code
    if (l == NULL)
        return -1;

    // Return OUT OF INDEX error code
    if (pos >= l->size)
        return -3;

    int i = 0;
    node *curr = l->head;

    while (i != pos) {
        ++ i;
        curr = curr->next;
    }

    l->assign(*item, curr->item);

    return 0;
}


int list_pop(list *l, void **item) {
    // Return NULL POINTER error
    if (l == NULL)
        return -1;

    // Return EMPTY LIST error
    if (l->head == NULL)
        return -4;

    node *curr = l->head;
    l->head = curr->next;
    l->assign(*item, curr->item);
    free(curr->item);
    free(curr);
    -- l->size;

    return 0;
}


int list_push(list *l, void *item, size_t size) {
    // Return NULL pointer error code
    if (l == NULL)
        return -1;

    node *n = (node *) malloc(sizeof(struct node));

    // Return OUT OF MEMORY error code
    if (n == NULL)
        return -2;

    n->item = malloc(size);

    // Also return OUT OF MEMORY error code
    if (n->item == NULL)
        return -2;

    l->assign(n->item, item);
    n->next = l->head;
    l->head = n;
    ++ l->size;

    return 0;
}


int list_size(list *l) {
    if (l == NULL)
        return -1;

    return l->size;
}
