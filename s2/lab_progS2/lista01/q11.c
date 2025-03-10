#include <stdio.h>

int main(){
    float reais, cotacao, dolares;

    puts("Insira a cotação: ");
    scanf("%f",&cotacao);

    puts("Insira a quantidade de reais: ");
    scanf("%f",&reais);

    dolares = reais/cotacao;
 
    printf("A quantidade de dólares é: %.2f\n",dolares);
 
    return 0;
}