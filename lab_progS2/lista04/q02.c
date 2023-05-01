#include <stdio.h>

void swap(int* , int* );

int main(){
    
    int num1 , num2;
    int *p1 = &num1, *p2 = &num2;

    puts("Insira o primeiro número: ");
    scanf("%i", p1);
    
    puts("Insira o segundo número: ");
    scanf("%i", p2); 

    swap(p1, p2);

    printf("O primeiro agora é:%i e o segundo agora é:%i\n", *p1, *p2);
    
    return 0;
}

void swap(int* p1, int* p2){

    int temp = *p1;
    *p1 = *p2;
    *p2 = temp; 

}