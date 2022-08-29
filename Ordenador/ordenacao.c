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
    




int mergesort(int *vetor, int inicio, int fim)
{
    if(inicio < fim)
    {
        //para toda vez que uma instancia dessa funcao e chamada
        //ele gera um novo meio e inicia novamente a recursividade
        int meio = (inicio + (fim - inicio) / 2);
                
        mergesort(vetor, inicio, meio);
        mergesort(vetor, meio + 1, fim);

        //quando inicio = fim a funcao termina sua instancia e retorna para instancia anterior
        //nesse retorno o segundo mergesort e chamado realizando o mesmo caminho da linha acima  
        //terminando as duas metades o merge e chamado realizando assim a ordenacao entre as duas mergesort dessa instancia
        //o processo se repete ate todas as instancias serem realizadas e terminar o primeiro mergesort chamado, com o vetor ordenado

        merge(vetor, inicio, meio, fim);
    }
}

void merge(int *vetor, int inicio, int meio, int fim)
{
    //n1 e n2 fazem parametro de comprimento para as metades dos vetores

    int n1 = meio - inicio + 1;
    int n2 = fim - meio;


    //referencias para ordenar ao vetor principal
    //e atribuir ao vetor principal tambem
    int *LVet, *MVet;

    LVet = (int *)calloc(n1, sizeof(int));
    MVet = (int *)calloc(n2, sizeof(int));


    for (int i = 0; i < n1; i++)
        *(LVet + i) = *(vetor + (inicio + i));

    for (int j = 0; j < n2; j++)
        *(MVet + j) = *(vetor + (inicio + j));

    //Variaveis de controle
    //i = posicao de referencia para a 1° metade
    //j = posicao de referencia para a 2° metade
    //k = posicao de referencia para o principal
    
    int i = 0, j = 0, k = inicio;

    while (i < n1 && j < n2) 
    {
        dado -> comparacoes++;

    //realiza a troca para o menor valor da posicao de referencia

        if(*(LVet + i) <= *(MVet + j))
           {
            *(vetor + k) = *(LVet + i);
            dado -> trocas++;
           }
        else
            {
             *(vetor + k) = *(MVet + j);
               dado -> trocas++;
               j++;
            } 
            k++;
        } 
    //atribui os valores das posicoes para, o vetor principal, do vetor que nao chegou ao fim
    while (i < n1) {
        *(vetor + k) = *(LVet + i);
        dado -> trocas++;
        i++;
        k++;
    }

    while (j < n2) {
        *(vetor + k) = *(MVet + j);
        dado -> trocas++;
        j++;
        k++;
    }

    dado -> varreduras++;
    free(LVet);
    free(MVet);
}  


void printvetor(const int *vetor, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(vetor + i));
    }
    printf("\n");
}

struct DADOS
{
    int trocas;
    int varreduras;
    int comparacoes;
}dados;

Dados *dadoscriar()
{
    Dados *inf = (Dados *) calloc(1, sizeof(Dados)); 
}
void dadosPrint(Dados *dado, FILE *arq, float tempo, int size)
  {
  fprintf(arq,"\n %d ; %f ; %d ; %d ; %d ", size, tempo, dado->trocas, dado->comparacoes, dado->varreduras);
  }

void dadosLiberar(Dados *dado)
  {
  free(dado);
  dado=NULL;
  }
