#include <stdio.h>

long Fatorial(int valor){
    if(valor > 1){
    return valor*(Fatorial(valor-1));
    } else {
        return 1;
    }
}

int main(){
    
    int valor;

    puts("Insira um inteiro positivo: ");
    scanf("%i",&valor);
    
    printf("O fatorial é:%li\n",Fatorial(valor));    
    
    return 0;
}