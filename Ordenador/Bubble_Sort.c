//Qtde de Trocas, Comparações e varreduras

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

void swap(int *a, int *b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}

void bubble(int vetor[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
           if (vetor[j] > vetor[j + 1])
           {
            swap(&vetor[j], &vetor[j + 1]);
           }
        }
    }
}

void printvetor(const int *vetor, int size)
{
    for (int i = 0; i < 9; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

}

int main()

{   
    clock_t tInicio, tFim;
    double tempo_gasto;
    
    tInicio = clock();

    int vetor[100000] = {rand() % 100000};

    bubble(vetor, 100000);
    //printvetor(vetor, 9);

    tFim = clock();

    tempo_gasto = ((double)(tFim - tInicio)) / CLOCKS_PER_SEC;
 
    printf("Tempo gasto: %f s\n", tempo_gasto);

return 0;
}

