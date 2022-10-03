#ifndef LISTA_DUPLA_H
#define LISTA_DUPLA_H

typedef struct LISTA dList;
typedef struct OBJETO vetor;

dList *listaCriar(float valor);
vetor *objetoCriar(float valor);
void listaInicio(dList *DL, float valor);
void listaFim(dList *DL, float valor);
void listaMeio(dList *DL, int posicao, float valor);
void listaImprimir(dList *DL);
void listaLiberar(dList *DL);
void listaDeletar(dList *DL, float valor);


#endif