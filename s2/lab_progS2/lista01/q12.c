#include <stdio.h>

int main(){
    int a,b;
    int soma, produto, diferenca, quociente, resto;

    puts("Insira o primeiro número: ");
    scanf("%i",&a);

    puts("Insira o segundo número: ");
    scanf("%i",&b);
    
    soma = a+b;

    produto= a*b;

    diferenca = a-b;

    quociente= a/b;

    resto = a%b;

    printf("Sua soma é: %i\n",soma);
    printf("Seu produto é: %i\n",produto);
    printf("Sua diferença é: %i\n",diferenca);
    printf("Seu quociente é: %i\n",quociente);
    printf("O resto da sua divisão é: %i\n",resto);

    return 0;
}