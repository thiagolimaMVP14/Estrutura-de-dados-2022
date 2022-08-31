#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include "Tads_ordenacao.h"

int main()
{
time_t merg_inicio, merg_final;
float merg_total;

dados *merge_info;
merge_info = dadosCriar();

int tamanho = 1000000; 
int inicio = 0, fim = (tamanho - 1);

int *merge_vector =(int *)malloc(tamanho * sizeof(int));

for(int g=0; g < tamanho; g++)
  *(merge_vector + g) = rand() % tamanho;

merg_inicio = clock();
mergesort(merge_vector, inicio, fim, merge_info);
merg_final = clock();
merg_total = ((float)(merg_final - merg_inicio) / CLOCKS_PER_SEC);

printf("\nTempo gasto: %f s\n", merg_total);


free(merge_vector);
dadosLiberar(merge_info);


merge_vector = NULL;

return 0;
}

