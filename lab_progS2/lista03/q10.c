#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define SIZE 5

void print_matrix(int array[][SIZE], int size);
int find_in_array(int array[],int size, int search);
int find_in_matrix(int array[][SIZE], int size, int search);

int main(){
    
    int search = 4;
    int matrix[SIZE][SIZE];
    int counter = 0; 
    
    srand(time(NULL));
    for(int i = 0; i<SIZE; i++){
        for(int j = 0; j<SIZE ; j++){
            matrix[i][j] = rand()%10;
        }
    }
    
    puts("Sua matrix é : ");
    print_matrix(matrix,SIZE);

    counter = find_in_matrix(matrix,SIZE,search);
    printf("O número %i aparece %i vezes na matrix.\n",search,counter);

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

int find_in_array(int array[],int size, int search){
    int counter =0;

    for(int i = 0; i<size ; i++){
        if(array[i]==search){
            counter++;
        }
    }

    return counter;
}

int find_in_matrix(int array[][SIZE], int size, int search){
    int counter = 0;

    for(int j=0; j<size ; j++){
        counter += find_in_array(array[j],size,search);
    }

    return counter;
}