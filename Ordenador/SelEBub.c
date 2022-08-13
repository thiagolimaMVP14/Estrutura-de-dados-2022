#include<stdlib.h>
#include<stdio.h>
#include"ordenacao.h"

int main()
{
    int size = 100000;
    
    int selectionVetor [100000];
    int bubbleVetor [100000];

    for(int i = 0; i < size; i++)
    {
        selectionVetor[i] = rand() % 100000;
    }

    for(int i = 0; i < size; i++)
    {
        bubbleVetor[i] = rand() % 100000; 
    }

    bubble(bubbleVetor, size);
    selection(selectionVetor, size);


    return 0;
}