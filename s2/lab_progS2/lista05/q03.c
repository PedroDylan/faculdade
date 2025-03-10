#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void gerarVetor(int* vetor, int size, int max);
void printVetor(int* vetor, int size);
int acharMenor(int *vetor, int size, int max);
int acharNoVetor(int* vetor, int size, int pesquisa);
int acharMaior(int *vetor, int size);
void criarVetorEndereços(int* vetor, int size,int max, int** enderecos);

int main(int argc, char* argv[]){
    
    if (argc!=2)
    {
        puts("número errado de inputs.");
        exit(1);
    }

    int size = atoi(argv[1]);
    int* vetor = (int*) malloc(size*sizeof(int));
    int menor,maior,posicaoMenor,posicaoMaior;
    int* endereços[2];

    if(!vetor){
        puts("Memória não alocada.");
        exit(2);
    }

    srand(time(NULL));
    gerarVetor(vetor,size,MAX);
    printVetor(vetor,size);

    criarVetorEndereços(vetor, size, MAX,endereços);

    printf("O endereço do menor valor é %p\n",endereços[0]);
    printf("O endereço do maior valor é %p\n",endereços[1]);

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

int acharMaior(int *vetor, int size){
    int maior = 0;

    for (int i = 0; i < size; i++)
    {
        if (*(vetor+i) > maior)
        {
            maior = *(vetor+i);
        }
        
    }
    return maior;
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

void criarVetorEndereços(int* vetor, int size,int max, int** enderecos){
    
    int menor = acharMenor(vetor,size,max);
    int maior = acharMaior(vetor,size);

    int posicaoMenor = acharNoVetor(vetor,size,menor);
    int posicaoMaior = acharNoVetor(vetor,size,maior);

    enderecos[0] = vetor+posicaoMenor;
    enderecos[1] = vetor+posicaoMaior;

}