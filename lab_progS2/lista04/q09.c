#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10
#define MAX 10
#define SFT 1

void troca(int *a, int *b);
void bubbleSort_p(int* vector, int size);

int main(){

    int vector[TAM];

    srand(time(NULL));
    for (int i = 0; i < TAM; i++)
    {
        *(vector+i) = rand()%MAX+SFT;       
    }
    
    printf("Vetor original.");
    for (int i = 0; i <TAM; i++)
    {
        printf("%i ",*(vector+i));
    }
    printf("\n");

    bubbleSort_p(vector,TAM);
    
    printf("Vetor organizado.");
    for (int i = 0; i <TAM; i++)
    {
        printf("%i ",*(vector+i));
    }
    printf("\n");



    return 0;
}

void troca(int *a, int *b){
    int dummy = *a;
    *a = *b;
    *b = dummy;
}

void bubbleSort_p(int* vector, int size){
    for (int pass = 0; pass < size-1; pass++)
    {
        for (int i = 0; i < size-1; i++)
        {
            if (*(vector+i) > *(vector+i+1))
            {
                troca(vector+i,vector+i+1);
            }
            
        }
        
    }
    
}
