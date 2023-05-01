#include <stdio.h>

int main(){
    
    int num1, num2, result;
    int *p1 = &num1, *p2 = &num2, *pr = &result;

    puts("Insira o primeiro número: ");
    scanf("%i",p1);

    puts("Insira o segundo número: ");
    scanf("%i",p2);

    *pr = *p1 + *p2;

    printf("A soma é %i e seu endereço é %p\n",result, pr);
    
    return 0;
}