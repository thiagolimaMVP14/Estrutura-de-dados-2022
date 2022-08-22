#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Tads_ordenacao.h"
#include <time.h>

void merge(int *vetor, int inicio, int meio, int fim);
void mergesort(int *vetor, int inicio, int fim);
void printmerge(int *vetor, int size)
{   
  for (int i = 0; i < size; i++)
    printf("%d ", vetor[i]);
  printf("\n");

}


int main()
{

   clock_t tInicio, tFim;
   float tempo_gasto;


   tInicio = clock();
    
   int TAM = 500000;

   int vetor[TAM];

   for(int i = 0; i < TAM; i++)
    {
    vetor[i] = rand() % 500000;
    }

   //printmerge(vetor, TAM);
   mergesort(vetor, 0, TAM - 1);
   //printmerge(vetor, TAM);
   printf("Tempo");
   tFim = clock();

   tempo_gasto = ((float)(tFim - tInicio)) / CLOCKS_PER_SEC;
 
   printf("Tempo gasto: %fs\n", tempo_gasto);
   printf("Tempo");

  

return 0;
}

