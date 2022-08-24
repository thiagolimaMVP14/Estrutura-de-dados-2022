//ASSINATURAS
typedef struct DADOS dados;


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

void merge(int *vetor, int inicio, int meio, int fim);

void mergesort(int *vetor, int inicio, int fim);

dados *dadosCriar();
void dadosPrint(dados *dado, FILE *arq, float tempo, int size);
void dadosLiberar(dados *dado);


//printa o vetor ja ordenado
void printvetor(const int *vetor, int size);


