#include <stdio.h>

int main(){
    int num;
    int centenas,pre_dezenas,dezenas,unidades;
    int novo;

    puts("Insira um número de 3 dígitos: ");
    scanf("%i",&num);

    /*321*/

    centenas = num/100; /*3*/
    pre_dezenas = (num - centenas*100);/*021*/
    dezenas = pre_dezenas/10;/*2*/
    unidades=pre_dezenas%10;/*1*/

    novo = unidades*100 + dezenas*10 + centenas;
    
    printf("O novo número é: %i\n",novo);

    return 0;
}