#include <stdio.h>

int main(){
    
    int numero;

    printf("Escreva um número: "); scanf("%i",&numero);

    printf("Seu triplo é : %i\n",3*numero);
    printf("Seu quadrado é : %i\n", numero*numero);
    printf("Seu meio é : %.2f\n", (float) numero/2);

    
    return 0;
}