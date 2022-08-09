#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "float_vector.h"


int main(int argc, char *argv[])
{
 FloatVector *vetor = create(5);

 append(vetor, 4);
 append(vetor, 8);
 append(vetor, 14);
 append(vetor, 18);
 append(vetor, 6);
 print(vetor);


 return 0;
}