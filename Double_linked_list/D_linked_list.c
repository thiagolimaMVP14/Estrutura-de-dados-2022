#include <stdio.h>
#include <stdlib.h>
#include "D_linked_list.h"

struct OBJETO
{
float valor;
vetor *next;
vetor *ant;
};

struct LISTA 
{
int size;
vetor *inicio;
vetor *fim;
};

vetor *vetorCriar(float valor)
{
vetor *vet =(vetor *)malloc(sizeof(vetor));
vet->next = vet;
vet->ant = vet;
vet->valor = valor;

return vet;
}

dList *listaCriar(float valor)
{
dList *DL =(dList *)calloc(1, sizeof(dList));
DL->inicio = vetorCriar(valor);
DL->fim = DL->inicio;
}

void listaInicio(dList *DL, float valor)
{
vetor *aux = DL->inicio;
vetor *novo =(vetor *)malloc(sizeof(vetor));
novo->next = DL->inicio;
novo->ant = DL->fim;
novo->valor = valor;
aux->ant = novo;

if(aux->next == aux)
  aux->next = novo;

DL->inicio = novo;
}

void listaFim(dList *DL, float valor)
{
vetor *aux = DL->fim;
vetor *novo =(vetor *)malloc(sizeof(vetor));
novo->next = DL->inicio;
novo->ant = DL->fim;
novo->valor = valor;
aux->next = novo;

if(aux->ant == aux)
  aux->ant = novo;

DL->fim = novo;
}

void listaImprimir(dList *DL)
{
vetor *aux = DL->inicio;
while(aux != DL->fim)
  {
  printf("[%.2f]->", aux->valor);
  aux = aux->next;
  }
printf("[%.2f]->(inicio)[%.2f]", aux->valor, DL->inicio->valor);
}

void listaLiberar(dList *DL)
{
vetor *aux;
while(aux != DL->fim)
  {  
  DL->inicio = aux->next;
  free(aux);
  aux = DL->inicio;
  }
free(aux);
free(DL);
}