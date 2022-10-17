#include <stdlib.h>
#include <stdio.h>
#include "D_linked_list.h"

int main()
{

int o = -1, pos = 0, posR = 0, sizeListaRef = 0, refLista = 1, tamL1=0, tamL2=0;
float valor = 0.0;
dList *lista, *lista1 = lCriar(), *lista2 = NULL;
lista = lista1;
printf("\n[LISTA DUPLAMENTE ENCADEADA]> Realize as funcoes disponiveis.\n");
    printf("\n [0] SAIR\n [1] ADD Inicio\n [2] ADD Final\n [3] ADD Escolha\n [4] TROCA\n [5] CONSULTA\n [6] ORDENAR\n [7] IMPRIRMIR LISTA\n [8] DELETAR ELEMENTO\n ESCOLHA: ");
    fflush(stdin);
    scanf("%d", &o);

do{
  switch (o)
    {
    case 1:
    system("cls");
    printf("\nINSIRA O VALOR> ");
    fflush(stdin);
    scanf("%f", &valor);
    
    lInicio(lista, valor);
    sizeListaRef++;
    o = -1;
    break;

    case 2:
    system("cls");
    printf("\nINSIRA O VALOR> ");
    fflush(stdin);
    scanf("%f", &valor);
    
    lFim(lista, valor);
    sizeListaRef++;
    o = -1;
    break;

    case 3:
    system("cls");
    printf("\nINSIRA O VALOR> ");
    fflush(stdin);
    scanf("%f", &valor);
    
    printf("\nTAMANHO> %d", sizeListaRef);
    printf("\nINSIRA A POSICAO> ");
    fflush(stdin);
    scanf("%d", &pos);
    lMeio(lista, pos, valor);
    sizeListaRef++;
    o = -1;
    break;

    case 4:
    system("cls");
    if(sizeListaRef > 1)
      {
      lImprimir(lista);
      printf("\nINSIRA POSICAO> ");
      fflush(stdin);
      scanf("%d", &pos);
      printf("\nINSIRA POSICAO> ");
      fflush(stdin);
      scanf("%d", &posR);
    
      lTroca(lista, pos, posR);
      }
    o = -1;
    break;

    case 5:
    system("cls");
    if(sizeListaRef > 0)
      {
      printf("\nTAMANHO> [%d]", sizeListaRef);
      printf("\nINSIRA POSICAO DE CONSULTA> ");
      fflush(stdin);
      scanf("%d", &pos);
      lConsulta(lista, pos);
      system("pause");
      }
    o = -1;
    break;

    case 6:
    system("cls");
    lImprimir(lista);
    lOrdenar(lista);
    lImprimir(lista);
    system("pause");
    o = -1;
    break;

    case 7:
    system("cls");
    lImprimir(lista);
    system("pause");
    o = -1;
    break;
    
    case 8:
    system("cls");
    if(sizeListaRef > 0)
      {
      lImprimir(lista);
      printf("\nINSIRA POSICAO QUE DESEJA EXCLUIR> ");
      fflush(stdin);
      scanf("%d", &pos);

      lDeletar(lista, pos);
      sizeListaRef--;
      }
    o = -1;
    break;
  
    case 9:
    system("cls");
    printf("teste");
    if(lista2 == NULL)
      {
      lista2 = lCriar();
      lista = lista2;
      refLista = 2;
      tamL1 = sizeListaRef;
      o = -1;
      break;
      }
    
    if(refLista == 1)
      {
      lista = lista2;
      refLista++;
      tamL1 = sizeListaRef;
      sizeListaRef = tamL2;
      o = -1;
      break;
      }
    else if(refLista == 2)
      {
      lista = lista1;
      refLista--;
      tamL2 = sizeListaRef;
      sizeListaRef = tamL1;
      o = -1;
      break;
      }
    o = -1;
    break;

    case 10:
    system("cls");
    if(lista2 == NULL) 
      {
      o = -1;  
      break;
      }
    lista1 = lUnir(lista1, lista2);
    lista = lista1;
    lista2 = NULL;
    refLista = 1;
    o = -1;
    break;

    default:
    system("cls");
    printf("\nLISTA [%d]>\n", refLista);
    printf("\n [0] SAIR\n [1] ADD Inicio\n [2] ADD Final\n [3] ADD Escolha\n [4] TROCA\n [5] CONSULTA");
    printf("\n [6] ORDENAR\n [7] IMPRIRMIR LISTA\n [8] DELETAR ELEMENTO\n [9] IR PARA OUTRA LISTA");
    printf("\n [10] UNIR LISTAS\n ESCOLHA: ");
    fflush(stdin);
    scanf("%d", &o);
    break;
  }
}while(o != 0);


lLiberar(lista1);
lLiberar(lista2);
system("cls");
return 0;
}