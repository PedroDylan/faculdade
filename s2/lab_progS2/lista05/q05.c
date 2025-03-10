#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarVetor(float* vector, int size);
void printVector(float* vector, int size);
float somaVetor(float* vector, int size);

int main(int argc, char* argv[]){
    
    if(argc != 2){
        puts("Número errado de inputs.");
        exit(1);
    }

    float soma;
    int size = atoi(argv[1]);
    float* vector = (float*) malloc(size*sizeof(float));

    if(!vector){
        puts("Memória não alocada.");
        exit(2);
    }
    
    srand(time(NULL));
    gerarVetor(vector,size);
    printVector(vector,size);
    soma = somaVetor(vector,size);

    printf("A soma é: %.2f\n", soma);

    free(vector);
    return 0;
}

void gerarVetor(float* vector, int size){
    for (int i = 0; i < size; i++)
    {
        *(vector+i) = ((float)rand()/(float)(RAND_MAX));
    }
}

void printVector(float* vector, int size){
    for (int i = 0; i < size; i++)
    {
        printf("%.2f\n",*(vector+i));       
    }
}

float somaVetor(float* vector, int size){
    float soma = 0;
    for (int i = 0; i < size; i++)
    {
        soma += *(vector+i);
    }
    return soma;
}