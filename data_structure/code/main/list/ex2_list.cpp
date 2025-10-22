#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*
   Print List (versión para caracteres)
*/
static void print_list(const List *list) {
    ListNode *node;
    char *data;
    int i;

    fprintf(stdout, "List size is %d\n", list_size(list));

    i = 0;
    node = list_head(list);

    while (1) {
        data = (char *)list_data(node);
        fprintf(stdout, "list.node[%03d] = %c, %p -> %p\n", i, *data, node, node->next);

        i++;

        if (list_is_tail(node))
            break;
        else
            node = list_next(node);
    }

    return;
}

int main(int argc, char **argv) {
    List list;
    ListNode *node;
    char *data;
    int i;

    // Inicializa la lista
    list_init(&list, free);

    // Llena la lista con las letras del alfabeto (A-Z)
    for (i = 0; i < 26; i++) {
        if ((data = (char *)malloc(sizeof(char))) == NULL)
            return 1;

        *data = 'A' + i;

        // Insertamos al inicio para mantener el orden inverso
        if (list_ins_next(&list, NULL, data) != 0)
            return 1;
    }

    print_list(&list);

    // Eliminar el nodo después del 7º nodo
    node = list_head(&list);
    for (i = 0; i < 7; ++i)
        node = list_next(node);

    data = (char *)list_data(node);
    fprintf(stdout, "\nRemoving a node after the one containing '%c'\n", *data);

    if (list_rem_next(&list, node, (void **)&data) != 0)
        return 1;

    print_list(&list);

    // Insertar 'Z' al final de la lista
    fprintf(stdout, "\nInserting 'Z' at the tail of the list\n");
    if ((data = (char *)malloc(sizeof(char))) == NULL)
        return 1;
    *data = 'Z';
    if (list_ins_next(&list, list_tail(&list), data) != 0)
        return 1;

    print_list(&list);

    // Eliminar nodo después del primero
    fprintf(stdout, "\nRemoving a node after the first node\n");
    if (list_rem_next(&list, list_head(&list), (void **)&data) != 0)
        return 1;
    print_list(&list);

    // Eliminar el nodo de la cabeza
    fprintf(stdout, "\nRemoving a node at the head of the list\n");
    if (list_rem_next(&list, NULL, (void **)&data) != 0)
        return 1;
    print_list(&list);

    // Insertar un nuevo carácter al inicio
    fprintf(stdout, "\nInsert 'X' at the head of the list\n");
    if ((data = (char *)malloc(sizeof(char))) == NULL)
        return 1;
    *data = 'X';
    if (list_ins_next(&list, NULL, data) != 0)
        return 1;
    print_list(&list);

    // Probar macros de verificación
    i = list_is_head(&list, list_head(&list));
    fprintf(stdout, "\nTesting list_is_head... value=%d (1=OK)\n", i);
    i = list_is_head(&list, list_tail(&list));
    fprintf(stdout, "Testing list_is_head... value=%d (0=OK)\n", i);
    i = list_is_tail(list_tail(&list));
    fprintf(stdout, "Testing list_is_tail... value=%d (1=OK)\n", i);
    i = list_is_tail(list_head(&list));
    fprintf(stdout, "Testing list_is_tail... value=%d (0=OK)\n", i);

    // Destruir la lista
    fprintf(stdout, "\nDestroying the list\n");
    list_destroy(&list);

    return 0;
}

