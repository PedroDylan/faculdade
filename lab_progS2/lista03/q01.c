#include <stdio.h>

#define SIZE 15

float find_max(float array[], int size);
float find_min(float array[], int size);
void print_array(float array[],int size);

int main(){
    
    float soma;
    float array[SIZE];

    puts("Insira os elementos do aray: ");
    for(int i=0; i<SIZE; i++){
        scanf("%f",&array[i]);
    }

    puts("Array: ");
    print_array(array,SIZE);

    printf("O máximo é : %.2f\n",find_max(array,SIZE));
    printf("O mínimo é : %.2f\n",find_min(array,SIZE));
    
    soma = find_max(array,SIZE) + find_min(array,SIZE);

    printf("A soma do máximo com o mínimo é :%f",soma);
    
    return 0;
}

float find_max(float array[], int size){
    float max = 0;

    for(int i = 0; i <size ; i++){
        if(array[i]>max){
            max=array[i];
        }
    }
    return max;
}

float find_min(float array[], int size){
    float min = sizeof(float);

    for(int i = 0; i<size; i++){
        if(array[i]<min){
            min = array[i];
        }
    }
    return min;
}

void print_array(float array[],int size){
    for(int i=0;i<size;i++){
        printf("%.2f\n",array[i]);
    }    
}
