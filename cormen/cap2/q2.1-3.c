#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void populateArray(int array[], int size);
void printArrayHorizontally(int array[], int size);
int linearSearch(int array[], int size, int search);

int main(int argc, char* argv[]){
    srand(time(NULL));

    if(argc != 3){
        printf("Quantidade Errada de inputs.\n");
        printf("Formatação correta: \n");
        printf("./q2.1-3.e {pesquisa} {tamanho}\n");
        exit(1);
    }
    
    int search = atoi(argv[1]);
    int size = atoi(argv[2]);
    int array[size];

    populateArray(array,size);
    printArrayHorizontally(array,size);

    int result = linearSearch(array,size,search);

    if(!result){
        printf("Achamos\n");
    } else {
        printf("Não achamos\n");
    }
    
    return 0;
}

