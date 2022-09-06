#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct _snode{
    int valor;
    SNode *prox;
}SNode;

typedef struct _slinked_list{
    SNode *inicio;
    int size;
}LinkedList;

SNode *SNode_criar(int valor){
    SNode *snode = (SNode*) calloc(1, sizeof(SNode));
    snode -> valor = valor;
    snode -> prox = NULL;
    return snode;
}

LinkedList *LinkedList_iniciar(int valor){
    LinkedList *L = (LinkedList*) calloc(1, sizeof(LinkedList));
    L -> inicio = SNode_criar(valor);
    L -> size++;
    return L;
}

void add_primeiro(LinkedList *L, int valor){
    if(L == NULL){
        L = LinkedList_iniciar(valor);
        return;
    }
    else{
    SNode *snode = (SNode *) calloc(1, sizeof(SNode));
    snode -> valor = valor;
    snode -> prox = L -> inicio;
    L -> inicio = snode;
    L -> size++;
}
}

void add_ultimo(LinkedList *L, int valor){
     if(L == NULL){
        L = LinkedList_iniciar(valor);
    }
    else{
        SNode *aux = L -> inicio;
        while(aux ->prox != NULL){
            aux = aux -> prox;
        }
    aux -> prox = LinkedList_iniciar(valor);      
    }
}

void add_meio (LinkedList *L, int pos, int valor){
    if(L -> size < pos){
        printf("\nInserido no final da lista\n");
        add_ultimo(L, valor);
    }
    if(L == NULL){
        L = LinkedList_iniciar(valor);
        return;
    }
    else{
        SNode *aux = L -> inicio;
        int i = 1;

        while(i < (pos - 1)){
            aux = aux -> prox;

            if(aux -> prox == NULL){
                SNode *snode = LinkedList_iniciar(valor);
                aux -> prox = snode;
                L -> size++;
                return;
            }
        i++;
        }
    SNode *snode = (SNode*) calloc(1, sizeof(SNode));
    snode -> valor = valor;
    snode -> prox = aux -> prox;
    aux -> prox = snode;
    L-> size++;    
    }    
}

void add_ordenado(LinkedList *L, int valor){
    if(L == NULL){
        L = LinkedList_iniciar(valor);
    }
    SNode *aux = L -> inicio;

    while(aux -> valor > valor){
        if(aux -> prox -> valor < valor){
            SNode *snode = (SNode*) calloc(1, sizeof(SNode));
            snode -> valor = valor;
            snode -> prox = aux -> prox;
            aux -> prox = snode;            
        }
    aux = aux -> prox;
    }
}

void printlist(LinkedList *L){
    SNode *aux = L -> inicio;
    printf("Tamanho: %d\n", L -> size);
    while(aux != NULL){
        printf("%d ", aux -> valor);
        aux = aux -> prox;
    }
    printf("[NULL]\n");
}