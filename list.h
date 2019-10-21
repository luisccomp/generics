#ifndef LIST_H
#define LIST_H

#define LIST_NULL_PTR      -1
#define LIST_OUT_OF_MEMORY -2
#define LIST_COPY_ERROR    -3
#define LIST_INDEX_ERROR   -4
#define LIST_NOT_FOUND     -5

typedef struct list list;

/**
 * Create an empty list and return the memory address where the list descriptor is.
 * If allocation tails, return a NULL pointer instead.
 * @param compare: a function that compare two elements on the list;
 * @param elem_size: the size of each element stored on the list;
 * @return: a memory address where the list descriptor is.
 */
list *list_create(int (*compare)(void *, void *), size_t elem_size);

/**
 * Destroy the linked list and every element stored on it. Also assign NULL as list's
 * memory address.
 * @param l_ptr: a pointer to a memory addres where the list descriptor is.
 */
void list_destroy(list **l_ptr);

/**
 * Get an element of a given position on the list.
 * @param l: a linked list;
 * @param pos: the position of element;
 * @param item: an address to a variable where the returned item will be stored;
 * @return: an error code.
 */
int list_get(list *l, int pos, void *item);

/**
 * Insert an element at the top of the list.
 * @param l: a linked list;
 * @param item: an item to be inserted;
 * @return: an error code.
 */
int list_push(list *l, void *item);

/**
 * Remove an item from a given position on the list.
 * @param l: a linked list;
 * @param pos: a position of an item to be removed;
 * @param item: an address of a variable to store the removed item;
 * @return: an error code.
 */
int list_remove(list *l, int pos, void *item);

/**
 * Remove an specific item from the list.
 * @param l: a linked list;
 * @param item: an item to be removed;
 * @return: an error code.
 */
int list_remove_item(list *l, void *item);

/**
 * Count how many elements was inserted on the list until the present moment.
 * @param l: a linked list;
 * @return: the list size or an error code.
 */
int list_size(list *l);

#endif // LIST_H