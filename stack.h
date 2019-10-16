#ifndef STACK_H
#define STACK_H

#define SUCCESS 0
#define STACK_NULL_PTR -5
#define STACK_EMPTY -3

typedef struct stack stack;

/**
 * Create an empty stack and return a pointer containing the address where
 * stack is stored.
 * @param assign: a pointer to a function that assign a value to a memory
 * address;
 * @param cmp: a pointer to a function that compare two values;
 * @param elem_size: the size (in bytes) of every element on the stack;
 * @return: a pointer to an empty stack or NULL if allocation fails.
 */
stack *stack_create(void (*assign)(void *, void *), int (*cmp)(void *, void *), size_t elem_size);

/**
 * Destroy the stack and every element stored on it.
 * @param ps: a pointer to an addres where stack is stored.
 */
void stack_destroy(stack **ps);

/**
 * Remove the element from the top of stack.
 * @param s: a stack;
 * @param item: a pointer to a variable to store the removed item.
 */
int stack_pop(stack *s, void **item);

/**
 * Insert an item on the stack.
 * @param s: a stack;
 * @param item: an item to be inserted;
 * @return: an error code.
 */
int stack_push(stack *s, void *item);

/**
 * Check the element on the top of stack.
 * @param s: a stack;
 * @param item: the address to the variable where you want to store the item.
 * @param: function error code.
 */
int stack_seek(stack *s, void **item);

#endif // STACK_H