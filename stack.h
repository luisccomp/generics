#ifndef STACK_H
#define STACK_H

#define STACK_NULL_PTR -8

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

/**
 * Get the element from the top of stack without removing it.
 * @param s: an stack;
 * @param element: an address to a variable to store element;
 * @return: an error code.
 */
int stack_peek(stack *s, void *element);

/**
 * Checks if the stack is empty.
 * @param s: a stack;
 * @return: an error code or if the stack is empty or not.
 */
int stack_is_empty(stack *s);

/**
 * Remove an element from the top of the stack.
 * @param s: a stack;
 * @param element: a pointer to a variable where the removed element will
 * be stored.
 */
void stack_pop(stack *s, void *element);

/**
 * Insert an element on the top of stack.
 * @param s: a stack;
 * @param element: an element to be inserted;
 * @return: an error code.
 */
int stack_push(stack *s, void *element);

/**
 * Count how many elements was inserted on the stack.
 * @param s: a stack;
 * @return: the stack size or an error code.
 */
int stack_size(stack *s);

#endif // STACK_H