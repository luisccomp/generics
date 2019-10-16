#include <stdlib.h>
#include "list.h"
#include "stack.h"

struct stack {
    list *l;
};

/**
 * Create an empty stack and return a pointer containing the address where
 * stack is stored.
 * @param assign: a pointer to a function that assign a value to a memory
 * address;
 * @param cmp: a pointer to a function that compare two values;
 * @param elem_size: the size (in bytes) of every element on the stack;
 * @return: a pointer to an empty stack or NULL if allocation fails.
 */
stack *stack_create(void (*assign)(void *, void *), int (*cmp)(void *, void *), size_t elem_size) {
    stack *s = (stack *) malloc(sizeof(struct stack));

    if (s != NULL) {
        s->l = list_create(assign, cmp, elem_size);

        if (s->l == NULL) {
            free(s);
            s = NULL;
        }
    }

    return s;
}

/**
 * Destroy the stack and every element stored on it.
 * @param ps: a pointer to an addres where stack is stored.
 */
void stack_destroy(stack **ps) {
    stack *s = *ps;

    if (s != NULL) {
        list_destroy(&(s->l));
        free(s);
        *ps = NULL;
    }
}

/**
 * Remove the element from the top of stack.
 * @param s: a stack;
 * @param item: a pointer to a variable to store the removed item.
 */
int stack_pop(stack *s, void **item) {
    if (s == NULL)
        return STACK_NULL_PTR;

    return list_pop(s->l, item);
}

/**
 * Insert an item on the stack.
 * @param s: a stack;
 * @param item: an item to be inserted;
 * @return: an error code.
 */
int stack_push(stack *s, void *item) {
    if (s == NULL)
        return STACK_NULL_PTR;

    return list_push(s->l, item);
}

/**
 * Check the element on the top of stack.
 * @param s: a stack;
 * @param item: the address to the variable where you want to store the item.
 * @param: function error code.
 */
int stack_seek(stack *s, void **item) {
    if (s == NULL)
        return STACK_NULL_PTR;

    return list_get(s->l, 0, item);
}
