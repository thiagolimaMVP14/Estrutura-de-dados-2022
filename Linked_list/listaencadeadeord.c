#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main()
{
    LinkedList *lista;
    lista = LinkedList_iniciar(1);
    add_ordenado(lista, 10);
    add_ordenado(lista, 7);
    add_ordenado(lista, 5);

    printlist(lista);
    return 0;    
}