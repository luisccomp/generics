#include <stdlib.h>
#include "list.h"
#include "stack.h"

struct stack {
    list *l;
};

/**
 * Create an empty stack and return an address to where stack descriptor is
 * stored.
 * @param elem_size: size of each element stored on stack;
 * @return: an address to stack descriptor or NULL if allocation fails.
 */
stack *stack_create(size_t elem_size) {
    stack *s = (stack *) malloc(sizeof(struct stack));

    if (s != NULL) {
        s->l = list_create(NULL, elem_size);

        if (s->l == NULL) {
            free(s);
            s = NULL;
        }
    }

    return s;
}

/**
 * Destroy the stack and every element stored on it. Also assign NULL ptr
 * to stack address.
 * @param: a pointer to a stack address.
 */
void stack_destroy(stack **stack_ptr) {
    if (*stack_ptr != NULL) {
        list_destroy(&(*stack_ptr)->l);
        free(*stack_ptr);
        *stack_ptr = NULL;
    }
}
