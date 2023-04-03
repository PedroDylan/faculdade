#include <stdio.h>

#define SIZE 3

void print_matrix(int array[][SIZE], int size);
void print_diag_princ(int array[][SIZE], int size);

int main(){

    int array[SIZE][SIZE];

    for(int i = 0; i<SIZE; i++){
        printf("Insira os elementos da linha %i\n",i);
        for(int j = 0; j<SIZE; j++){
            scanf("%i",&array[i][j]); 
        }
    }

    puts("Sua matrix é: ");
    print_matrix(array,SIZE);

    puts("A diagonal principal é :");
    print_diag_princ(array,SIZE);

    return 0;
}

void print_matrix(int array[][SIZE], int size){
    for (int i = 0; i<size ; i++){
        for (int j = 0; j < SIZE; j++)
        {
            printf(" %i ",array[i][j]);
        }
        puts("\n");
    }
}

void print_diag_princ(int array[][SIZE], int size){
    
    int diagonal[size];
    int counter = 0;  

    for(int i = 0; i<size; i++){
        for(int j = 0; j<SIZE; j++){
            if (i==j)
            {
                diagonal[counter]=array[i][j];
                counter++;
            }
        }
    }

    for(int k = 0; k<size; k++){
        printf("%i ",diagonal[k]);
    }
    puts("\n");
}