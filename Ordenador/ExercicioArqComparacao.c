#include <stdio.h>
#include "Tads_ordenacao.h"
#include <stdlib.h>


int main()
{

    FILE *arq;
    int size = 1000;


    arq = fopen("Numeros dos algoritmos de ordenacao.txt", "a");

    int *bubbleVetor = (int *)malloc(size * sizeof(int));
    int *selectionVetor = (int *)malloc(size * sizeof(int));

    bubble(bubbleVetor, size, arq);
    selection(selectionVetor, size, arq);

    free(bubbleVetor);
    free(selectionVetor);

    bubbleVetor = NULL;
    selectionVetor = NULL;

    return 0;
}
