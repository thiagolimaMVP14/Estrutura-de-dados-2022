#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Tads_ordenacao.h"
#include <time.h>

int main()
{
   FILE *arq;
   arq = fopen("Dados_dos_Ordenadores.csv", "a");

   time_t mInicio, mFim;
   double tempo_gasto;
   
   dados *info_merge;
   info_merge = dadoscriar();

   
    
   int TAM = 1000000, t = 0;

   int *vetor = (int*) malloc(TAM * sizeof(int));

   for(int i = 0; i < TAM; i++){
      *(vetor + i) = rand() % TAM;
   }
   
   mInicio = clock();
   mergesort(vetor, 0, TAM - 1, info_merge);
   mFim = clock();
   
   tempo_gasto = (((double)(mFim - mInicio)) / CLOCKS_PER_SEC);
   printf("Tempo gasto: %fs\n", tempo_gasto);

   dadosImprimir(info_merge, arq, tempo_gasto, TAM);
 

   free(vetor);
   liberarDados(info_merge);

   vetor = NULL;
  

return 0;
}

