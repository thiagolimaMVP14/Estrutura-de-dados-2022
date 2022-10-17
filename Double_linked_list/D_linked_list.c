#include <stdio.h>
#include <stdlib.h>
#include "D_linked_list.h"

struct OBJETO
{
float valor;
vetor *next;
vetor * anterior;
};

struct LISTA 
{
int size;
vetor *inicio;
vetor *fim;
};

vetor *vetorCriar(float valor)
{
vetor *vector =(vetor *)malloc(sizeof(vetor));
vector->next = vector;
vector-> anterior = vector;
vector->valor = valor;

return vector;
}

dList *lCriar()
{
dList *DL =(dList *)calloc(1, sizeof(dList));
DL->inicio = NULL;
DL->fim = DL->inicio;
}

void lTroca(dList *DL, int p1, int p2)
{
if(p1 <= 0 || p2 <= 0 || p1 > DL-> size || p2 > DL-> size || p1 == p2) return;

vetor *aux1, *aux2, *refA, *refP;

if(p1 <= DL-> size/2)
  {
  aux1 = DL->inicio;
  for(int n = 1; n < p1; n++)
    aux1 = aux1-> next;
  }else if(p1 > DL-> size/2)
    {
    aux1 = DL->fim;
    for(int n = DL-> size; n > p1; n--)
      aux1 = aux1-> anterior;    
    }
  
if(p2 <= DL-> size/2)
  {
  aux2 = DL->inicio;
  for(int n = 1; n < p2; n++)
    aux2 = aux2->next;
  }else if(p2 > DL-> size/2)
    {
    aux2 = DL->fim;
    for(int n = DL-> size; n > p2; n--)
      aux2 = aux2-> anterior;
    }
  
  refA = aux1-> anterior;
  refP = aux1->next;
  refA->next = aux2;
  refP-> anterior = aux2;
  aux1->next = aux2->next;
  aux1-> anterior = aux2-> anterior;
  aux2-> anterior = refA;
  aux2->next = refP;
  refA = aux1-> anterior;
  refA->next = aux1;
  refP = aux1->next;
  refP-> anterior = aux1;

if(p1 == 1)
  DL->inicio = aux2;

if(p1 == DL-> size)
  DL->fim = aux2;

if(p2 == 1)
  DL->inicio = aux1;

if(p2 == DL-> size)
  DL->fim = aux1;


printf("\nTROCA REALIZADA> [%d] <-> [%d]\n", p1, p2);
}

void lInicio(dList *DL, float valor)
{
  if(DL -> inicio == NULL)
  {
  DL-> inicio = vetorCriar(valor);
  DL-> fim = DL->inicio;
  DL-> size ++;
  return;
  }

vetor *aux = DL->inicio;
vetor *novo =(vetor *)malloc(sizeof(vetor));
novo->next = DL->inicio;
novo-> anterior = DL->fim;
novo->valor = valor;
aux-> anterior = novo;

if(aux->next == aux)
  aux->next = novo;

DL->inicio = novo;
}

void lFim(dList *DL, float valor)
{
  if(DL -> inicio == NULL)
  {
  DL-> inicio = vetorCriar(valor);
  DL-> fim = DL-> inicio;
  DL-> size++;
  return;
  }

vetor *aux = DL->fim;
vetor *novo =(vetor *)malloc(sizeof(vetor));
novo->next = DL->inicio;
novo-> anterior = DL->fim;
novo->valor = valor;
aux->next = novo;

if(aux-> anterior == aux)
  aux-> anterior = novo;

DL->fim = novo;
}

void lMeio(dList *DL, int posicao, float valor)
{
if((posicao > (DL -> size + 1)) || posicao <= 0 || DL->inicio == NULL) return;

vetor *aux, *novo;

if(posicao <= DL -> size/2)
  {
  aux = DL->inicio;
  for(int n = 1; n < posicao; n++)
    aux = aux -> next;

  novo =(vetor *)malloc(sizeof(vetor));
  novo -> valor = valor;
  novo -> next = aux;
  novo -> anterior = aux -> anterior;
  aux -> anterior = novo;
  aux = novo -> anterior;
  aux -> next = novo;
  DL-> size++;
  }
else
  {
  aux = DL->fim;
  for(int n = DL-> size; n > posicao; n--)
    aux = aux -> anterior;

  novo =(vetor *)malloc(sizeof(vetor));
  novo -> valor = valor;
  novo -> next = aux;
  novo -> anterior = aux -> anterior;
  aux -> anterior = novo;
  aux = novo -> anterior;
  aux -> next = novo;
  DL-> size++;
  }

if(posicao == 1)
  DL->inicio = novo;

if(posicao == DL -> size)
  DL -> fim = novo;

printf("\nINSERIDO> [%d](%.2f)\n", posicao, valor);
}

//ordenacao feita pela lógica de selection sort
void lOrdenar(dList *DL)
{
if(DL->inicio == NULL) return;

vetor *aux, *ref, *troca;
float T;

for(aux = DL->inicio; aux -> next != DL -> inicio; aux = aux -> next)
  {
  troca = aux;
  
  for(ref = DL -> fim; ref != aux; ref = ref -> anterior)
    if(troca -> valor > ref -> valor)
      troca = ref;
  
  T = troca -> valor;
  troca -> valor = aux -> valor;
  aux -> valor = T;
  }

printf("\n[ORDENADO]\n");
}


void lConsulta(dList *DL, int posicao)
{
if(posicao <= 0 || posicao > DL -> size || DL -> inicio == NULL) return;

if(posicao <= DL -> size/2)
  {
  vetor *aux = DL -> inicio;
  for(int n = 1; n < posicao; n++)
    aux = aux -> next;

  printf("\nPOSICAO> [%d]\nVALOR> (%.2f)\n", posicao, aux -> valor);
  }
else
  {
  vetor *aux = DL -> fim;
  for(int n = DL -> size; n > posicao; n--)
    aux = aux -> anterior;
  
  printf("\nPOSICAO> [%d]\nVALOR> (%.2f)\n", posicao, aux -> valor);
  }
}


void lDeletar(dList *DL, int posicao)
{
if(posicao <= 0 || posicao > DL -> size || DL -> inicio == NULL) return;

vetor *aux, *auxR;

if(posicao == 1)
  {
  aux = DL -> inicio; 
  auxR = DL -> fim;
  DL -> inicio = aux -> next;
  auxR -> next = DL -> inicio;
  auxR = aux -> next;
  auxR -> anterior = DL -> fim;
  
  printf("\nOBJETO> [%d](%.2f) (excluido)\n", posicao, aux -> valor);

  free(aux);
  aux=NULL;
  DL -> size--;
  system("pause");
  return;
  }

if(posicao == DL -> size)
  {
  aux = DL -> fim;
  auxR = DL -> inicio;
  DL -> fim = aux -> anterior;
  auxR -> anterior = DL -> fim;
  auxR = aux -> anterior;
  auxR -> next = DL -> inicio;

  printf("\nOBJETO> [%d](%.2f) (excluido)\n", posicao, aux -> valor);

  free(aux);
  aux=NULL;
  DL -> size--;
  system("pause");
  return;
  }

if(posicao <= DL -> size/2)
  {
  aux = DL -> inicio;
  vetor *ref_A, *ref_P;
  for(int n = 1; n < posicao; n++)
    aux = aux -> next;

  ref_A = aux -> anterior;
  ref_P = aux -> next;

  ref_A -> next = ref_P;
  ref_P -> anterior = ref_A;
  }
else
  {
  aux = DL -> fim;
  vetor *ref_A, *ref_P;
  for(int n = DL -> size; n > posicao; n--)
    aux = aux -> next;

  ref_A = aux -> anterior;
  ref_P = aux -> next;

  ref_A -> next = ref_P;
  ref_P -> anterior = ref_A;
  }

  printf("\nOBJETO> [%d](%.2f) (excluido)\n", posicao, aux -> valor);


  free(aux);
  aux = NULL;
  DL -> size--;
  system("pause");
  return;
  
}


dList *lUnir(dList *DL1, dList *DL2)
{
dList *nLista = lCriar();

lOrdenar(DL1);
lOrdenar(DL2);

int R1 = 1, R2 = 1;

vetor *aux1 = DL1 -> inicio, *aux2 = DL2 -> inicio;

while(R1 <= DL1 -> size && R2 <= DL2 -> size)
  {
    if(aux1 -> valor <= aux2 -> valor)
      {
      lFim(nLista, aux1 -> valor);
      aux1 = aux1 -> next;
      R1++;
      }
    else
      {
      lFim(nLista, aux2 -> valor);
      aux2 = aux2 -> next;
      R2++;
      }
  }

while(R1 <= DL1 -> size)
  {
  lFim(nLista, aux1 -> valor);
  aux1 = aux1 -> next;
  R1++;
  }

while(R2 <= DL2 -> size)
  {
  lFim(nLista, aux2 -> valor);
  aux2 = aux2 -> next;
  R2++;  
  }

lLiberar(DL1);
lLiberar(DL2);

return nLista;
}


void lImprimir(dList *DL)
{
vetor *aux = DL -> inicio;
while(aux != DL -> fim)
  {
  printf("[%.2f] -> ", aux -> valor);
  aux = aux -> next;
  }
printf("[%.2f] -> (inicio)[%.2f]", aux -> valor, DL -> inicio -> valor);
}


void lLiberar(dList *DL)
{
vetor *aux;
while(aux != DL -> fim)
  {  
  DL -> inicio = aux -> next;
  free(aux);
  aux = DL -> inicio;
  }
free(aux);
free(DL);
}