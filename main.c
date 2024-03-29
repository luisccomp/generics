#include <stdio.h>
#include "list.h"

int compare(void *a, void *b) {
    return *((int *) a) - *((int *) b);
}

void show_list(list *l) {
    printf(":.:.:.: List :.:.:.:\n");

    for (int i = 0; i < list_size(l); i ++) {
        int a;

        if (list_get(l, i, (void *) &a)) {
            printf("ERROR\n");
            break;
        }
        else {
            printf("item[%d] = %d\n", i, a);
        }
    }

    printf("--------------------\n");
}

int main(int argc, char **argv) {
    list *l = list_create(compare, sizeof(int));
    int option = 1;

    while (option != 0) {
        printf("Select an option:\n");
        printf("1. Show list;\n");
        printf("2. Insert an element at the top;\n");
        printf("3. Remove an element by position;\n");
        printf("4. Remove an element;\n");
        printf("5. Insert an item at the end of list;\n");
        printf("6. Remove an element from the top;\n");
        printf("0. Exit.\n");
        printf("> ");
        scanf("%d", &option);

        int item, element, removed;

        switch (option) {
            case 1:
                show_list(l);
                break;
            case 2:
                printf("Type an element: ");
                scanf("%d", &item);
                
                if (list_push(l, (void *) &item))
                    printf("ERROR\n");
                else
                    printf("Inserted successfuly\n");

                break;
            case 3:
                printf("Enter the position of element: ");
                int pos;
                scanf("%d", &pos);

                if (list_remove(l, pos, (void *) &removed))
                    printf("ERROR\n");
                else {
                    printf("Removed: %d\n", removed);
                }

                break;
            case 4:
                printf("Type the element you want to be removed: ");
                scanf("%d", &element);

                if (list_remove_item(l, (void *) &element))
                    printf("ERROR\n");
                else
                    printf("Element removed successfully\n");

                break;
            case 5:
                printf("The the element you want to be inserted: ");
                scanf("%d", &item);

                if (list_append(l, (void *) &item))
                    printf("ERROR\n");
                else
                    printf("Inserted successfully\n");

                break;
            case 6:
                if (list_pop(l, (void *) &element))
                    printf("ERROR\n");
                else
                    printf("Removed: %d\n", element);
                    
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Unknown option!\n");
        }
    }

    list_destroy(&l);
    return 0;
}
