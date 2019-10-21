#ifndef STACK_H
#define STACK_H

typedef struct stack stack;

/**
 * Create an empty stack and return an address to where stack descriptor is
 * stored.
 * @param elem_size: size of each element stored on stack;
 * @return: an address to stack descriptor or NULL if allocation fails.
 */
stack *stack_create(size_t elem_size);

/**
 * Destroy the stack and every element stored on it. Also assign NULL ptr
 * to stack address.
 * @param: a pointer to a stack address.
 */
void stack_destroy(stack **stack_ptr);

#endif // STACK_H