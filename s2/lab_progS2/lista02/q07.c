#include <stdio.h>
#include <stdlib.h>

int main(){
    
    float num1, num2;

    puts("Insira dois números a serem divididos: ");
    scanf("%f",&num1);
    scanf("%f",&num2);

    if(num2==0){
        printf("Divisão por 0 impossível.\n");
        exit(1);
    } else {
        printf("%f\n",num1/num2);
    }
    
    return 0;
}