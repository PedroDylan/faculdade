#include <stdio.h>

int main(){
    int a,b;
    int dummy;

    puts("Insira o primeiro número a: ");
    scanf("%i",&a);

    puts("Insira o segundo número b: ");
    scanf("%i",&b);

    dummy = a;
    a = b;
    b = dummy;

    printf("Novo a: %i, novo b: %i\n",a,b);



    return 0;
}