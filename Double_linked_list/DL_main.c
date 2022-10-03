#include <stdlib.h>
#include <stdio.h>
#include "D_linked_list.h"

int main()
{

dList *DL = listaCriar(33.3);
listaInicio(DL, 42.5);
listaInicio(DL, 21.4);
listaFim(DL, 55);

listaImprimir(DL);

listaLiberar(DL);

return 0;
}