//Qtde de Trocas, Comparações e varreduras

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "ordenacao.h"


int main()

{   
    clock_t tInicio, tFim;
    double tempo_gasto;
    
    tInicio = clock();

    int size = 100000;
    int vetor[100000];

    for(int i = 0; i < size; i++)
    {
        vetor[i] = rand() % 100000;
    }

    bubble(vetor, 100000);
    //printvetor(vetor, 9);

    tFim = clock();

    tempo_gasto = ((double)(tFim - tInicio)) / CLOCKS_PER_SEC;
 
    printf("Tempo gasto: %f s\n", tempo_gasto);

return 0;

}

