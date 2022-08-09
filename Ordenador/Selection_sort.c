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
    
    //inicio da contagem de tempo gasto
    tInicio = clock();

    //define o tamanho do vetor
    int size = 100000;
    int vetor[100000];

    //criação do vetor
    for(int i = 0; i < size; i++)
    {
        vetor[i] = rand() % 100000;
    }

    //chamando as funções
    
    //printvetor(vetor, 9);
    selection(vetor, 100000);
    

    //Fim da contagem de tempo
    tFim = clock();

    //Resultado final da contagem de tempo
    tempo_gasto = ((double)(tFim - tInicio)) / CLOCKS_PER_SEC;
 
    printf("Tempo gasto: %f s\n", tempo_gasto);

return 0;

}