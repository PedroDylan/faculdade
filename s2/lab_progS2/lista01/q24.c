#include <stdio.h>
#include <math.h>

int main(){
    int escalar, expoente;
    int resultado;

    puts("Insira o escalar: "); scanf("%i",&escalar);
    puts("Insira o expoente: "); scanf("%i",&expoente);
    
    resultado = escalar*pow(2,expoente);

    printf("O resultado é: %i\n",resultado);
    
    
    
    
    
    return 0;
}