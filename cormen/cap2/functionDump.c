#include "functionDump.h"
#include <stdio.h>
#include <stdlib.h>

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

void populateArray(int array[], int size){
    for(int i = 0 ; i < size ; i++){
        *(array+i) = rand()%100;
    }
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

int linearSearch(int array[], int size, int search){
    for(int i = 0; i<size; i++){
        if(array[i]==search){
            return 0;
            break;            
        }
    }
    return 1;
}