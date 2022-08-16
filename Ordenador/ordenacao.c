#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tads_ordenacao.h"
#include <time.h>



void swap(int *a, int *b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}

void bubble(int *vetor, int size, FILE *arq)
{

    clock_t bInicio, bFinal;
    float bTotal;

    int troca = 0, varredura = 0, comparacao = 0;

    bInicio = clock();


      for(int t = 0; t < size; t++)
    {
        *(vetor + t) = rand() % 100000;
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


bFinal = clock();
bTotal = ((float)(bFinal - bInicio) / CLOCKS_PER_SEC);

fprintf(arq,"\nBubble Sort:");
fprintf(arq,"\nTempo total gasto: %f segundos", bTotal);
fprintf(arq,"\nTrocas: %d\nComparacoes: %d\n,Varreduras: %d\n", troca, comparacao, varredura);
}

void selection (int *vetor, int size, FILE *arq)
{

  clock_t sInicio, sFinal;
  double sTotal;

  int troca = 0, varredura = 0, comparacao = 0;

  sInicio = clock();

  for(int t = 0; t < size; t++)    
  {
    *(vetor + t) = rand() % 100000;
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
sFinal = clock();
sTotal = ((double) (sFinal - sInicio)/ CLOCKS_PER_SEC);

fprintf(arq,"\nSelection Sort:");
fprintf(arq,"\nTempo total gasto: %f segundos", sTotal);
fprintf(arq,"\nTrocas: %d\nComparacoes: %d\n,Varreduras: %d\n", troca, comparacao, varredura);
}
    
void merge (int array[], int inicio, int meio, int fim)
{
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int L[n1];
    int R[n2];

    for(int i = 0; i < n1; i++)
    {
        L[i] = array[inicio + i];
    }

    for(int i = 0; i < n2; i++)
    {
        R[i] = array[inicio + i];
    }

    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

}


int mergesort(int array[], int inicio, int fim)
{
    if(inicio < fim)
    {
        int meio = inicio + (fim - inicio)/2;
        
        
        mergesort(array, inicio, meio);
        mergesort(array, meio + 1, fim);
        merge(array, inicio, meio, fim);
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
