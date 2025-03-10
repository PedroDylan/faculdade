#include <stdio.h>

int ePar(int num){
    return num%2;

}

int main(){
    int num;

    puts("Insira um número e diremos se é par(0) ou ímpar(1): ");
    scanf("%i",&num);

    printf("%i\n",ePar(num));
    
    return 0;
}