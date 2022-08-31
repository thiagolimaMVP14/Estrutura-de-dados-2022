#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tads_ordenacao.h"
#include <time.h>
#include <math.h>

struct DADO
{
    int trocas;
    int varreduras;
    int comparacoes;
}DADO;

dados *dadosCriar()
  {
  dados *info = (dados *)calloc(1, sizeof(dados));
  return info;
  }

void dadosPrint(dados *dado, FILE *arq, float tempo, int size)
  {
  fprintf(arq,"\n %d ; %f ; %d ; %d ; %d ", size, tempo, dado->trocas, dado->comparacoes, dado->varreduras);
  }

void dadosLiberar(dados *dado)
  {
  free(dado);
  dado=NULL;
  }

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

fprintf(arq,"\nSelection Sort (%d):", size);
fprintf(arq,"\nTempo total gasto: %f segundos", sTotal);
fprintf(arq,"\nTrocas: %d\nComparacoes: %d\nVarreduras: %d\n", troca, comparacao, varredura);
}

void merge(int *vetor, int inicio, int meio, int fim, dados *dado)
{
    //n1 e n2 fazem parametro de comprimento para as metades dos vetores

  int n1 = meio - inicio + 1;
  int n2 = fim - meio;


    //referencias para ordenar ao vetor principal e atribuir ao vetor principal tambem
    int *sVet1, *sVet2;

    sVet1 =(int *)calloc(n1, sizeof(int));
    sVet2 =(int *)calloc(n2, sizeof(int));


   for(int n = 0; n < n1; n++)
    *(sVet1 + n) = *(vetor + (inicio + n));

   for(int n = 0; n < n2; n++)  
    *(sVet2 + n) = *(vetor + ((meio + 1) + n));

    //Variaveis de controle
    //i = posicao de referencia para a 1° metade
    //j = posicao de referencia para a 2° metade
    //k = posicao de referencia para o principal
    
    int i = 0, j = 0, k = inicio;

    while (i < n1 && j < n2) 
    {
        dado->comparacoes++;

    //realiza a troca para o menor valor da posicao de referencia

        if(*(sVet1 + i) <= *(sVet2 + j))
           {
            *(vetor + k) = *(sVet1 + i);
            dado -> trocas++;
           }
        else
            {
             *(vetor + k) = *(sVet2 + j);
               dado -> trocas++;
               j++;
            } 
            k++;
        } 
    
    //atribui os valores das posicoes para, o vetor principal, do vetor que nao chegou ao fim
    while (j < n2) {
        *(vetor + k) = *(sVet2 + j);
        dado -> trocas++;
        j++;
        k++;
    }

    while (i < n1) {
        *(vetor + k) = *(sVet1 + i);
        dado -> trocas++;
        i++;
        k++;
    }

    dado->varreduras++;
    free(sVet1);
    free(sVet2);
}

int mergesort(int *vetor, int inicio, int fim, dados *dado)
{
  int meio;

    if(inicio < fim)
    {
        //para toda vez que uma instancia dessa funcao e chamada
        //ele gera um novo meio e inicia novamente a recursividade
        meio = inicio + (fim - inicio)/2;
        mergesort(vetor, inicio, meio, dado);
        mergesort(vetor, meio+1, fim, dado);

        //quando inicio = fim a funcao termina sua instancia e retorna para instancia anterior
        //nesse retorno o segundo mergesort e chamado realizando o mesmo caminho da linha acima  
        //terminando as duas metades o merge e chamado realizando assim a ordenacao entre as duas mergesort dessa instancia
        //o processo se repete ate todas as instancias serem realizadas e terminar o primeiro mergesort chamado, com o vetor ordenado

        merge(vetor, inicio, meio, fim, dado);
    }
} 

int quick(int *vetor, int inicio, int fim, dados *dado)
  {
  int left = inicio, right = fim, pivo = *(vetor + inicio);

//VERIFICACAO DE VETOR JA ORDENADO 
  int g = 0;
  while(*(vetor + g) < *(vetor + g + 1))
    {
    g++;
    if(g == fim)
      return 0;
    }
/*
comparacao com o pivo feita da esquerda para a direita e da direita para a esquerda
o lado esquerdo recebe os valores menores ou iguais ao pivo
o lado direito vai receber os valores maiores que o pivo
ai a troca e feita entre as referencias da esquerda e da direita
*/

   while(left < right)
    {
    while(*(vetor + left) <= pivo)
    {
    dado->comparacoes++;
    left++;
    }
    
    while(*(vetor + right) > pivo)
    {
    dado->comparacoes++;
    right--;
    }

    if(left < right)
    {
    dado->trocas++;
    swap((vetor + right), (vetor + left));  
    }
    }

/*coloca o pivo entre as posicoes de esquerda e direita, ficando assim na posicao correta do vetor
pivo que e o inicio troca com o ultima posicao dos valores menores que ele(right)*/    
    
    *(vetor + inicio) = *(vetor + right);
    *(vetor + right) = pivo;
    return right;
  }

void quicksort(int *vetor, int inicio, int fim, dados *dado)
  {
  if(inicio < fim)
    {
    int pivo = quick(vetor, inicio, fim, dado);
    quicksort(vetor, inicio, pivo - 1, dado);
    quicksort(vetor, pivo + 1, fim, dado);
    }
  }
     
void printvetor(const int *vetor, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(vetor + i));
    }
    printf("\n");
}


