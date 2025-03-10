#include <stdio.h>

int main(){
    int valor;

    puts("Insira um valor: ");
    scanf("%i",&valor);

    printf("Seu antecessor é: %i , e seu sucessor é: %i\n",valor-1,valor+1);
    
    return 0;
}