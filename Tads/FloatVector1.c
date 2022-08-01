utu//Arquivo de Implementações
#include "FloatVector.h"

struct FloatVector
{
    int capacity; //numero maximo de elemento
    int size; //qtde atual de elementos
    int *data; //vetor de floats
};

FloatVector *create(int tam)
{
    FloatVector *vet = (FloatVector *) calloc(1, sizeof(FloatVector));
    vet -> capacity = tam;
    vet -> size = 0;
    vet -> data = (float*) calloc(vet->capacity, sizeof(float));

    return vet;
};

void destroy(FloatVector **vet_ref)
{
    FloatVector *vet = vet_ref;
    free(vet->data);
    free(vet);
}
//codigo de hoje