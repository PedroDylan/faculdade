#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10
#define N 10
#define SFT 1

int contaNumeros(int *vector, int numero, int size);

int main(){

    int X[TAM];
    int F[N];

    srand(time(NULL));
    for (int i = 0; i < TAM; i++)
    {
        *(X+i) = rand()%(N-1)+SFT;       
    }

    for (int i = 0; i < TAM; i++)
    {
        *(F+i) = contaNumeros(X,i,TAM);
    }
    
    puts("Vetor original.");
    for (int i = 0; i < TAM; i++)
    {
        printf("%i ",*(X+i));       
    }
    printf("\n");

    puts("Vetor de aparições");
    for (int i = 0; i < N; i++)
    {
        printf("%i ",*(F+i));
    }
    printf("\n");

    return 0;
}

int contaNumeros(int *vector, int numero, int size){

    int counter = 0;

    for (int i = 0; i < size; i++)
    {
        if (*(vector+i)==numero)
        {
            counter++;
        }
    }

    return counter;
}