#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void createArray(int array[], int size);
void printArray(int array[], int size);
void insertionSorting(int array[], int size);
void printArrayHorizontally(int array[], int size);

int main(int argc, char* argv[]){
    srand(time(NULL));
    
    int size = atoi(argv[1]);

    int array[size];

    createArray(array,size);
    printArrayHorizontally(array,size);
    printf("Fim do array oiginal.\n");

    insertionSorting(array,size);


    printArrayHorizontally(array,size);
    
    return 0;
}

void createArray(int array[], int size){
    for(int i = 0 ; i < size ; i++){
        *(array+i) = rand()%100;
    }
}

void printArray(int array[], int size){
    for (int i = 0; i<size;i++){
        printf("%i\n",array[i]);
    }
}

void printArrayHorizontally(int array[], int size){
    for(int i = 0; i<size; i++){
        if(i>0 && i%10 == 0){
            printf("\n");
        }
        printf("%.2i ",array[i]);
    }
    printf("\n");
}

void insertionSorting(int array[], int size){
    for(int j=1; j<size; j++){
        int key = array[j];
        int i = j-1;
        while(i>=0 && array[i]>key){
            array[i+1] = array[i];
            i = i-1;
        }
        array[i+1] = key;
    }
}