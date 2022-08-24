#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Tads_ordenacao.h"
#include <time.h>

void merge(int *vetor, int inicio, int meio, int fim);
void mergesort(int *vetor, int inicio, int fim);



int main()
{
    
   //FILE *arq;

   //arq = fopen("Dados_dos_Ordenadores.csv", "a"); 

   time_t mInicio, mFim;
   float tempo_gasto;
   
   //dados *info_merge;
   //info_merge = dadoscriar();

   
    
   int TAM = 550000, t = 0;

   int *vetor = (int*) malloc(TAM * sizeof(int));

   while(t < TAM)
    {
    *(vetor + t) = rand() % 550000;
    t++;
    }
   
   mInicio = clock();
   mergesort(vetor, 0, TAM - 1);
   mFim = clock();
   //printvetor(vetor, TAM);
   tempo_gasto = (((float)(mFim - mInicio)) / CLOCKS_PER_SEC);

   //dadosImprimir(info_merge, arq, tempo_gasto, TAM);
 
   printf("Tempo gasto: %fs\n", tempo_gasto);

   free(vetor);
   //liberarDados(info_merge);

   vetor = NULL;
  

return 0;
}

