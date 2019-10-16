#include <stdio.h>
#include "list.h"

void assign(void *pa, void *pb) {
    int *a = (int *) pa;
    int *b = (int *) pb;

    *a = *b;
}

int compare(void *pa, void *pb) {
    int va = *((int *) pa);
    int vb = *((int *) pb);

    return va - vb;
}

void show_list(list *l) {
    printf(":.:.:.: List :.:.:.:\n");
    printf("List size: %d\n", list_size(l));

    for (int i = 0; i < list_size(l); i ++) {
        void *item;
        int a;
        item = (void *) &a;
        list_get(l, i, &item);
        printf("item[%d] = %d\n", i, a);
    }
    
    printf("--------------------\n");
}

int main(int argc, char **argv) {
    // Creating and "teatching" a list how to compare and assign its elements
    list *l = list_create(assign, compare, sizeof(int));

    int run = 1;

    printf(":.:.:.: Lista encadeada :.:.:.:\n");

    while (run) {
        printf("Selecione uma opcao:\n");
        printf("1. Exibir lista\n");
        printf("2. Inserir um elemento no inicio da lista\n");
        printf("3. Inserir um elemento no final da lista\n");
        printf("0. Sair\n");
        int option;
        printf("> ");
        scanf("%d", &option);

        switch (option) {
            case 0:
                run = 0;
                printf("Saindo...\n");
                break;
            case 1:
                show_list(l);
                break;
            case 2:
                printf("Digite o elemento a ser inserido na lista: ");
                int item;
                scanf("%d", &item);

                if (list_push(l, (void *) &item) == 0)
                    printf("Item inserido com sucesso!");
                else
                    printf("Algo errado aconteceu!");

                break;
            default:
                printf("Opcao invalida...\n");
        }
    }

    list_destroy(&l);

    return 0;
}
