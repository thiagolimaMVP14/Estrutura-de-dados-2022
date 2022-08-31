//ASSINATURAS

typedef struct DADO dados;

//Faz a troca dos valores no vetor
void swap(int *a, int *b);

//Faz a comparacao sempre com a posicao adjacente
//Caso a posicao atual seja maior que a proxima ocorre a troca
//Leva o maior valor para a proxima posicao
void bubble(int *vetor, int size, FILE *arq);

//Faz a comparacao da posicao atual com todas as outras
//Caso a posicao atual seja maior que algum valor do vetor percorrido
//o menor valor e armazenado na primeira posicao depois do menor valor anterior
void selection(int *vetor, int size, FILE *arq);

//faz a separacao do vetor ate tamanho do vetor = 1
int mergesort(int *vetor, int inicio, int fim, dados *dado);

//chamada para ordenar os vetores da instancia que o processo estiver
void merge(int *vetor, int inicio, int meio, int fim, dados *dado);

void quicksort(int *vetor, int inicio, int fim, dados *dado);

int quick(int *vetor, int inicio, int fim, dados *dado);

dados *dadosCriar();

void dadosPrint(dados *dado, FILE *arq, float tempo, int size);

void dadosLiberar(dados *dado);

//printa o vetor ja ordenado
void printvetor(const int *vetor, int size);


