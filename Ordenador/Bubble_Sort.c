//Qtde de Trocas, Comparações e varreduras

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "Tads_ordenacao.h"


int main()

{   
    clock_t tInicio, tFim;
    float tempo_gasto;
    
    //inicio da contagem de tempo gasto
    tInicio = clock();

    //define o tamanho do vetor
    int size = 8, t = 0;
    
    //criação do vetor
    int *vetor = (int *) malloc(size * sizeof(int));

    printf("Vetor sem ordenacao:");
    while(t < size)
    {
      *(vetor + t) =  rand() % 10;
      printf("[%d]", *(vetor + t));
      t++;
    }
   

    //chamando as funções
    bubble(vetor, size);
    printf("\n\nVetor com ordenacao:");
    printvetor(vetor, size);
    
    

    //Fim da contagem de tempo
    tFim = clock();

    //Resultado final da contagem de tempo
    tempo_gasto = ((float)(tFim - tInicio)) / CLOCKS_PER_SEC;
 
    printf("Tempo gasto: %f s\n", tempo_gasto);

    free(vetor);
    vetor = NULL;

return 0;
}

