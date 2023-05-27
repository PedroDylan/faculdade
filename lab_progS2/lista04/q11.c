//&(x,y) = &(0,0) + x + y*N
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

struct Par
{
    int x;
    int y;
};

void generateRanVector(int *vector, int size, int max);
void printVector(int *vector, int size);
int generateElement(int *matrix, int dimension, struct Par ponto);
void printMatrix(int* matrix, int dimension);

int main(){
    
    int N = 7;
    int X[TAM], Y[TAM];
    struct Par pares[TAM];
    int matrix[N*N];

    for (int i = 0; i < N*N; i++)
    {
        matrix[i]=0;
    }

    srand(time(NULL));
    generateRanVector(X,TAM,N);
    generateRanVector(Y,TAM,N);

    for (int i = 0; i < TAM; i++)
    {
        pares[i].x = Y[i];
        pares[i].y = X[i];
    }
    
    for (int i = 0; i < TAM; i++)
    {
        *(matrix + pares[i].x + N*pares[i].y) = generateElement(matrix,N,pares[i]);
    }
    

    printVector(X,TAM);
    printVector(Y,TAM);
    printMatrix(matrix, N);

    return 0;
}

void generateRanVector(int *vector, int size, int max){
    for (int i = 0; i < size; i++)
    {
        *(vector+i)=rand()%(max);
    }
}

void printVector(int *vector, int size){
    for (int i = 0; i < size; i++)
    {
        printf("%i ",*(vector+i));
    }
    printf("\n");
    
}

int generateElement(int *matrix, int dimension, struct Par ponto){

    int local = *(matrix + ponto.x + (ponto.y*dimension));
    
    return (local+1);

}

void printMatrix(int* matrix, int dimension){

    for (int i = 0; i < dimension*dimension; i++)
    {
        if(i%dimension==0){
            printf("\n");
        }

        printf("%i ",*(matrix+i));
    }
    printf("\n");
}
