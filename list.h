#ifndef LIST_H
#define LIST_H

// Some error codes
#define SUCCESS 0
#define LIST_NULL_PTR -1
#define LIST_OUT_OF_MEM -2
#define LIST_OUT_OF_INDEX -3
#define LIST_EMPTY -4

typedef struct list list;

/**
 * Insert an item at the end of the list.
 * @param l: a linked list;
 * @param item: an item to be inserted;
 * @return: an error code indicating if insertion is successful or not.
 */
int list_append(list *l, void *item);

/**
 * Check if list contains or not a given element.
 * @param l: a linked list;
 * @param item: an item;
 * @return: an error code or a idication if list contains or not the given element.
 */
int list_contains(list *l, void *item);

/**
 * Create a new and empyt list and return a pointer to a memory address where
 * this list is stored.
 * @param assign: a pointer to a function that assugign a value to a memory
 * address;
 * @param cmp: a pointer to a function that compare two values;
 * @param elem_size: the size (in bytes) of every element on the list;
 * @return: a pointer to an empty linked list or NULL if allocation fails.
 */
list *list_create(void (*assign)(void *, void *), int (*cmp)(void *, void *), size_t elem_size);

/**
 * Destroy the linked list and its stored elements. After destroy everything,
 * this function will assign NULL to the pointer for futher uses.
 * @param l: a pointer to a linked list address.
 */
void list_destroy(list **pl);

/**
 * Checks if a list is empty or not.
 * @param l: a linked list;
 * @return: an error code or an indication if list is empty or not.
 */
int list_empty(list *l);

/**
 * Get an especific element on a given position inside the list.
 * @param l: a linked list;
 * @param pos: the position of element;
 * @param item: a pointer to a variable where you want to store the given item;
 * @return: the function error code.
 */
int list_get(list *l, int pos, void **item);

/**
 * Remove the first element of a list;
 * @param l: a linked list;
 * @param item: a pointer to a variable to store the removed item;
 * @return: function error code.
 */
int list_pop(list *l, void **item);

/**
 * Insert a new item on the top of the list.
 * @param l: a linked list;
 * @param item: an item to be inserted;
 * @return: return an error code indicating if operation was successful or not.
 */
int list_push(list *l, void *item);

/**
 * Count the number of elements the current list contains.
 * @param l: a linked list;
 * @return: an error code or the size of the list.
 */
int list_size(list *l);
#endif // LIST_H