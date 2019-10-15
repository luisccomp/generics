#ifndef LIST_H
#define LIST_H
typedef struct list list;

/**
 * Insert an item at the end of list.
 * @param l: a pointer to linked list.
 * @param item: an item to be inserted on list.
 * @param size: the size of item in bytes.
 * @return: the error code of function.
 */
int list_append(list *l, void *item, size_t size);

/**
 * Create an empty list and return a pointer to it. The programmer might inform, by using
 * two functions, the list how to compare and assign elements of list.
 * parameters:
 *     assign -> a function to assign an value to another.
 *     compare -> a function to compare two items.
 * return:
 *     A pointer to an empty list or null, if allocation fails.
 */
list *list_create(void (*assign)(void *, void *), int (*compare)(void *, void *));

/**
 * Destroy the list and the items stored on it.
 * parameters:
 *     l -> linked list pointers.
 */
void list_destroy(list *l);

/**
 * Get an item from the linked list.
 * parameters:
 *     l -> a pointer to linked list.
 *     item -> a pointer to store returned item.
 * return:
 *     An error code telling if function operation was successfull or not.
 */
void list_get(list *l, int pos, void **item);

/**
 * Remove an item from the top of the list.
 * parameters:
 *     l -> a pointer to linked list.
 *     item -> a pointer to a variable to store the returned item.
 * return:
 *     The function error code.
 */
int list_pop(list *l, void **item);

/**
 * Insert an item on the top of the list.
 * parameters:
 *     l -> a pointer to a linked list.
 *     item -> a new item to insert on list.
 *     size -> the size of item in bytes.
 */
int list_push(list *l, void *item, size_t size);

/**
 * Count how many items are inserted inside of list.
 * parameters:
 *     l -> pointer to linked list
 * return:
 *     The size of list or an error code.
 */
int list_size(list *l);

#endif // LIST_H
