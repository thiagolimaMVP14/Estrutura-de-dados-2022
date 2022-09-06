#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct _snode SNode;
typedef struct _slinked_list LinkedList;

SNode *SNode_criar(int valor);

LinkedList *LinkedList_iniciar();

void addprimeiro(LinkedList *L, int valor);

void listaAddInicio(LinkedList *L, int valor);

void listaAddFinal(LinkedList *L, int valor);

void listaAddMeio(LinkedList *L, int pos, int valor);

void add_ordenado(LinkedList *L, int valor);

void listaImprimir(LinkedList *L);

#endif 