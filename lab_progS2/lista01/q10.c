#include <stdio.h>

int main(){
    int comprimento, altura, largura, volume;

    puts("Insira o comprimento");
    scanf("%i",&comprimento);

    puts("Insira a largura");
    scanf("%i",&largura);

    puts("Insira a altura");
    scanf("%i",&altura);

    volume = comprimento*altura*largura;
    
    printf("O volume é: %i\n", volume);

    return 0;
}