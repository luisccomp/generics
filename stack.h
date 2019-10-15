#ifndef STACK_H
#define STACK_H

typedef struct stack stack;

stack *stack_create(void (*assign)(void *, void *), void (*compare)(void *, void *));

void stack_destroy(stack *s);

int stack_pop(stack *s, void **item);

int stack_push(stack *s, void *item, size_t size);

int stack_size(stack *s);

#endif // STACK_H
