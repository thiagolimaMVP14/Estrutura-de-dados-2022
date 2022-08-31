#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Tads_ordenacao.h"

int main()
{
time_t quick_i, quick_f;
float quick_t;

dados *info;
info = dadosCriar();

int size = 500000;
int inicio = 0, fim = (size - 1);

int *vet =(int *)malloc(size * sizeof(int));

for(int n = 0; n < size; n++)
  *(vet + n) = rand() % size;

quick_i = clock();
quicksort(vet, inicio, fim, info);
quick_f = clock();

quick_t = ((float)(quick_f - quick_i) / CLOCKS_PER_SEC);

printf("\n(TEMPO DE EXECUCAO): %f(s)\n", quick_t);

free(vet);
dadosLiberar(info);

vet = NULL;
return 0;
}