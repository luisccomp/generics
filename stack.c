#include <stdlib.h>
#include "list.h"
#include "stack.h"

struct stack {
    list *l;
};

stack *stack_create(void (*assign)(void *, void *), void (*compare)(void *, void *)) {
    stack *s = (stack *) malloc(sizeof(struct stack));

    if (s != NULL) {
        s->l = list_create(assign, compare);

        if (s->l == NULL) {
            free(s);
            return NULL;
        }
    }

    return s;
}


void stack_destroy(stack *s) {
    if (s != NULL) {
        list_destroy(s->l);
        free(s);
    }
}


int stack_pop(stack *s, void **item) {
    // Return NULL POINTER error code
    if (s == NULL)
        return -1;

    return list_pop(s->l, item);
}


int stack_push(stack *s, void *item, size_t size) {
    // Return NULL POINTER error code
    if (s == NULL)
        return -1;

    return list_push(s->l, item, size);
}


int stack_size(stack *s) {
    // Return NULL POINTER error code
    if (s == NULL)
        return -1;

    return list_size(s->l);
}
