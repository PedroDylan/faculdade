#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void gerarVetor(int* vetor, int size, int max);
void printVetor(int* vetor, int size);
int acharMenor(int *vetor, int size, int max);
int acharNoVetor(int* vetor, int size, int pesquisa);

int main(int argc, char* argv[]){
    
    if (argc!=2)
    {
        puts("número errado de inputs.");
        exit(1);
    }

    int size = atoi(argv[1]);
    int* vetor = (int*) malloc(size*sizeof(int));
    int menor,posicao;

    if(!vetor){
        puts("Memória não alocada.");
        exit(2);
    }

    srand(time(NULL));
    gerarVetor(vetor,size,MAX);
    printVetor(vetor,size);

    menor = acharMenor(vetor,size,MAX);
    posicao = acharNoVetor(vetor,size,menor);

    printf("o menor número do vetor é %i e está na posição %i\n",menor,posicao);
    printf("Seu endereço é %p\n",vetor+posicao);

    free(vetor);
    return 0;
}

void gerarVetor(int* vetor, int size, int max){
    for (int i = 0; i < size; i++)
    {
        *(vetor+i) = rand()%max;
    }
}

void printVetor(int* vetor, int size){
    for (int i = 0; i < size; i++)
    {
        printf("Valor: %i, endereço: %p\n",*(vetor+i),vetor+i);
    }
    printf("\n");   
}

int acharMenor(int *vetor, int size, int max){
    int menor = max;

    for (int i = 0; i < size; i++)
    {
        if (*(vetor+i) < menor)
        {
            menor = *(vetor+i);
        }
        
    }
    return menor;
}

int acharNoVetor(int* vetor, int size, int pesquisa){
    int i = 0;
    for ( ; i < size; i++)
    {
        if (*(vetor+i)==pesquisa)
        {
            break;
        }
    }
    return i;
}