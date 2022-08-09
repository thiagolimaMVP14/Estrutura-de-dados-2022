#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenacao.h"



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