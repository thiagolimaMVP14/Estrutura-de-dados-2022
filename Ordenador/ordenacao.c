#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenacao.h"
#include <time.h>



void swap(int *a, int *b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}

void bubble(int vetor[], int size)
{

    clock_t bubbleInicio, bubbleFinal;
    double bubbleTime;

    int troca = 0, varredura = 0, comparacao = 0;

    bubbleInicio = clock();


      for(int i = 0; i < size; i++)
    {
        vetor[i] = rand() % 100000;
    }

    //POSICAO DE COMPARACAO COM O VETOR
    for (int i = 0; i < size - 1; i++)
    {

        //PERCORRE O VETOR SEMPRE COM UMA POSICAO A MENOS
        //ULTIMA POSICAO DE TROCA JA ESTA COM O MAIOR MAIOR VALOR
        for (int j = 0; j < size - 1; j++)
        {

            //CASO SEJA MAIOR VALOR TROCA COM O PROXIMO
            //NA ULTIMO POSICAO POSSIVEL FICARA O MAIOR NUMERO
           if (vetor[j] > vetor[j + 1])
           {
            swap(&vetor[j], &vetor[j + 1]);
            troca++;
           }
        comparacao++;   
        }
    varredura++;    
    }
}

bubbleFinal = clock();
bubbleTime = ((double)(bubbleFinal - bubbleInicio) / CLOCKS_PER_SEC);

printf("Tempo total gasto: %f segundos", bubbleTime);
printf("\nTrocas: %d\nComparacoes: %d\n,Varreduras: %d\n", troca, comparacao, varredura);


void selection (int vetor[], int size)
{

  clock_t selectionInicio, selectionFinal;
  double selectionTime;

  int troca = 0, varredura = 0, comparacao = 0;

  selectionInicio = clock();

  for(int i = 0; i < size; i++)    
  {
    vetor[i] = rand() % 100000;
  }

    for (int i = 0; i < size; i++)
    {
        //armazena a posicao que sera comparada com o vetor
        int menor = i; 
        
        //faz a comparacao com a posicao armazenada no menor
        for (int j = i; j < size; j++) 
        {
            //caso o valor do vetor que percorre seja menor que o armazenado anteriormente 
            //a menor posicao já armazenada atualiza com a posicao nova de menor valor
            if(vetor[j] < vetor [menor])
              {
                menor = j;
              } 
            comparacao++;       
        }
        //faz a troca dos valores "menor" atualizado e da posicao(em ordem 'i') que sera trocada
        //caso a referencia('i') seja a mesma que o menor, nao ocorre a troca

        if(i != menor) 
        {
          swap(&vetor[i], &vetor [menor]);
          troca++;    
        }
    varredura++;    
}
    selectionFinal = clock();
    selectionTime = ((double) (selectionFinal - selectionInicio)/ CLOCKS_PER_SEC);

  printf("Tempo total gasto: %f segundos", selectionTime);
  printf("\nTrocas: %d\nComparacoes: %d\n,Varreduras: %d\n", troca, comparacao, varredura);

    

void printvetor(const int *vetor, int size)
{
    for (int i = 0; i < 9; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

}
