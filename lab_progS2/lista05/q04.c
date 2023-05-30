#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define TAM 10

void gerarVetor(int* vetor, int size, int max);
void printVetor(int* vetor, int size);
int acharMenor(int *vetor, int size, int max);
int acharMaior(int *vetor, int size);
int criarDenominador(int* vetor,int size, int max);
void criarNovoVetor(int* X, float* Y, int denominador, int size, int max);

int main(){

    int X[TAM];
    float Y[TAM];
    int denominador;

    srand(time(NULL));
    gerarVetor(X,TAM,MAX);
    denominador = criarDenominador(X,TAM,MAX);
    criarNovoVetor(X,Y,denominador,TAM,MAX);

    puts("Vetor X:");
    printVetor(X,TAM);
    printf("Menor: %i\n",acharMenor(X,TAM,MAX));
    printf("Maior: %i\n",acharMaior(X,TAM));
    printf("Denominador: %i\n",criarDenominador(X,TAM,MAX));

    puts("Vetor normalizado:");
    printf("[");
    for (int i = 0; i < TAM; i++)
    {
        printf("%.2f ,",*(Y+i));
    }
    printf("]\n");

    return 0;
}

void gerarVetor(int* vetor, int size, int max){
    for (int i = 0; i < size; i++)
    {
        *(vetor+i) = rand()%max;
    }
}

void printVetor(int* vetor, int size){
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%i ",*(vetor+i));
    }
    printf("]");
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

int criarDenominador(int* vetor,int size, int max){
    int menor = acharMenor(vetor,size,max);
    int maior = acharMaior(vetor,size);
    
    return maior - menor;
}

void criarNovoVetor(int* X, float* Y, int denominador, int size, int max){

    int menor = acharMenor(X,size,max);

    for (int i = 0; i < size; i++)
    {
        *(Y+i) = (float)(*(X+i)-menor)/denominador;
    }
}