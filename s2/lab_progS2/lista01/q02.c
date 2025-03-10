#include <stdio.h>

int main(){
    
    int valor;

    printf("Insira o valor: "); scanf("%i",&valor);
    
    printf("valor em base 10: %i\n",valor);

    printf("valor em base 8: %o\n",valor);

    printf("valor em base 16: %x\n",valor);
    
    return 0;
}