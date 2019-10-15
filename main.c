#include <stdio.h>
#include "list.h"

void assign(void *pa, void *pb) {
    int *a = (int *) pa;
    int *b = (int *) pb;

    // Make an assignment between two void pointers
    *a = *b;
}


int compare(void *pa, void *pb) {
    int va = *((int *) pa);
    int vb = *((int *) pb);

    // Compare those two values by subtraction
    return va - vb;
}


void show_list(list *l) {
    printf("--- LIST ---\n");
    printf("Size: %d\n", list_size(l));

    for (int i = 0; i < list_size(l); i ++) {
        void *item;
        list_get(l, i, &item);
        printf("Item[%d]: %d\n", i, *((int *) item));
    }

    printf("------------\n");
}

int main(void) {
    list *l = list_create(assign, compare);
    int a = 1;
    list_push(l,(void *) &a, sizeof(int));
    a = 2;
    list_push(l,(void *) &a, sizeof(int));
    a = 3;
    list_push(l,(void *) &a, sizeof(int));
    a = 4;
    list_push(l,(void *) &a, sizeof(int));
    show_list(l);
    list_destroy(l);

    return 0;
}
