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
fprintf(arq,"\nTrocas: %d\nComparacoes: %d\nVarreduras: %d\n", troca, comparacao, varredura);
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
    
void merge(int *vetor, int inicio, int meio, int fim)
{
    int tamanho, n1, n2, *temp, i, j, k;
    int fim1 = 0, fim2 = 0;
    
    tamanho = fim - inicio + 1;
    n1 = inicio;
    n2 = meio + 1;
    temp = (int *)malloc(tamanho * sizeof(int));

    if(temp != NULL)
    {
        for(i = 0; i < tamanho; i++)
        {
            if (!fim1 && !fim2)
            {
                if (vetor[n1] < vetor[n2])
                   temp[i] = vetor[n1++];
                else
                   temp[i] = vetor[n2++];
            
                if (n1 > meio)
                   fim1 = 1;
                if(n2 > meio)
                   fim2 = 2;   
            }else
                {
                    if(!fim1)
                       temp[i] = vetor[n1++];
                    else
                       temp[i] = vetor[n2++];
                }
            
        }
        for (j = 0, k = inicio; j < tamanho; j++, k++)
        {
            vetor[k] = temp[j];
        }     
    }
    free(temp);    
}



void mergesort(int *vetor, int inicio, int fim)
{
    if(inicio < fim)
    {
        int meio = ((inicio + fim) /2);
                
        mergesort(vetor, inicio, meio);
        mergesort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }
}


void printvetor(int *vetor, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
