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

/**
 * Checks if the stack is empty.
 * @param s: a stack;
 * @return: an error code or if the stack is empty or not.
 */
int stack_is_empty(stack *s) {
    if (s == NULL)
        return STACK_NULL_PTR;

    return list_is_empty(s->l);
}

/**
 * Get the element from the top of stack without removing it.
 * @param s: an stack;
 * @param element: an address to a variable to store element;
 * @return: an error code.
 */
int stack_peek(stack *s, void *element) {
    if (s == NULL)
        return STACK_NULL_PTR;

    return list_get(s->l, 0, element);
}

/**
 * Remove an element from the top of the stack.
 * @param s: a stack;
 * @param element: a pointer to a variable where the removed element will
 * be stored.
 */
void stack_pop(stack *s, void *element) {
    if (s == NULL)
        return STACK_NULL_PTR;

    return list_pop(s->l, element);
}

/**
 * Insert an element on the top of stack.
 * @param s: a stack;
 * @param element: an element to be inserted;
 * @return: an error code.
 */
int stack_push(stack *s, void *element) {
    if (s == NULL)
        return STACK_NULL_PTR;

    return list_push(s->l, element);
}

/**
 * Count how many elements was inserted on the stack.
 * @param s: a stack;
 * @return: the stack size or an error code.
 */
int stack_size(stack *s) {
    if (s == NULL)
        return STACK_NULL_PTR;

    return list_size(s->l);
}
