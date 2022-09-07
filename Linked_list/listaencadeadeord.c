#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main()
{
    LinkedList *lista;
    lista = LinkedList_iniciar(1);
    add_ordenado(lista, 10);
    add_ordenado(lista, 7);
    add_ordenado(lista, 15);
    add_ordenado(lista, 50);
    add_ordenado(lista, 45);
    add_ordenado(lista, 5);


    listaImprimir(lista);
    freelista(lista);

    printf("\nLista Vazia:\n");

    return 0;    
}