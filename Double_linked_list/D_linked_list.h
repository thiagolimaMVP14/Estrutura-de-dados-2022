#ifndef LISTA_DUPLA_H
#define LISTA_DUPLA_H

typedef struct LISTA dList;
typedef struct OBJETO vetor;

dList *lCriar();
vetor *vetorCriar(float valor);
void lInicio(dList *DL, float valor);
void lFim(dList *DL, float valor);
void lMeio(dList *DL, int posicao, float valor);
void lOrdenar(dList *DL);
void lTroca(dList *DL, int p1, int p2);
void lImprimir(dList *DL);
void lConsulta(dList *DL, int posicao);
void lLiberar(dList *DL);
void lDeletar(dList *DL, int posicao);
dList *lUnir(dList *DL1, dList *DL2);


#endif