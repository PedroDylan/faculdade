#include <stdio.h>

int main(){
    
    float numero;

    printf("Escreva um valor: "); scanf("%f",&numero);  

    numero += (numero*0.1);

    printf("O valor com 10%% é %.2f\n",numero);  
    
    return 0;
    
}