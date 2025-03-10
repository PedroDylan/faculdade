#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int valor,modulo;

    puts("Insira um valor: ");
    scanf("%i",&valor);

    modulo = fabs(valor);

    printf("Seu módulo é: %i\n",modulo);

    
    
    
    return 0;
}