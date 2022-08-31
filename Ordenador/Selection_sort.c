//Qtde de Trocas, Comparações e varreduras

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "Tads_ordenacao.h"


int main()

{   
    FILE *arq;
    arq = fopen("Dados_dos_Ordenadores.csv", "a"); 

    clock_t tInicio, tFim;
    double tempo_gasto;
    
    //inicio da contagem de tempo gasto
    tInicio = clock();

    //define o tamanho do vetor
    int size = 1000000, x = 0;
    
    //criação do vetor
    
    int *vetor = (int *) malloc(size * sizeof(int));

 
    while(x < size)
    {
      *(vetor + x) =  rand() % 10;
      x++;
    }

    //inicio da contagem de tempo gasto
    tInicio = clock();
    //chamando as funções
    selection(vetor, size, arq);
    //Fim da contagem de tempo
    tFim = clock();

    //Resultado final da contagem de tempo
    tempo_gasto = ((double)(tFim - tInicio)) / CLOCKS_PER_SEC;
 
    printf("Tempo gasto: %f s\n", tempo_gasto);


    free(vetor);
    vetor = NULL;

return 0;
}