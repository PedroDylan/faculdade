#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void populateArray(int array[], int size);
void printArray(int array[], int size);
void insertionSorting(int array[], int size);
void printArrayHorizontally(int array[], int size);

int main(int argc, char* argv[]){
    srand(time(NULL));

    if(argc != 2){
        printf("Quantidade Errada de inputs.\n");
        printf("Formatação correta: \n");
        printf("./q2.1.e {tamanho}\n");
        exit(1);
    }
    
    int size = atoi(argv[1]);

    int array[size];

    populateArray(array,size);
    printArrayHorizontally(array,size);
    printf("Fim do array oiginal.\n");

    insertionSorting(array,size);


    printArrayHorizontally(array,size);
    
    return 0;
}
