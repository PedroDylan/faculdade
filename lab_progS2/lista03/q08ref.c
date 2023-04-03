#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

#define SIZE 100

int main(){

    int lim_inf, lim_sup;
    int array[SIZE];

    puts("Insira o limite inferior e o superior: ");
    scanf("%i",&lim_inf);
    scanf("%i",&lim_sup);

    srand(time(NULL));

    for(int i = 0; i <SIZE ;i++){
        array[i] = rand()%(lim_sup - lim_inf) + lim_inf;
    }
    
    ref_sort(array,SIZE);

    puts("Array ordenado: ");
    printArray(array,SIZE);

    return 0;
}