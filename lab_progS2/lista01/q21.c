#include <stdio.h>

int eMult(int a, int b){
    return a%b;
}

int main(){
    int a,b;

    puts("Insira dois números e diremos se são múltiplos(0) ou não(!=0): ");
    scanf("%i",&a);
    scanf(" %i",&b);

    printf("%i\n",eMult(a,b));
    
    return 0;
}