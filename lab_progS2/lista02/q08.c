#include <stdio.h>

int checkMult(int dividendo, int divisor){
    if( dividendo%divisor==0 && divisor!=0 && dividendo!=0){
        return 0;
    } else {
        return 1;
    }
}

int main(){

    float valor,entrada;
    float centavos;
    int dummy,parcelas;
    

    puts("Insira o valor da compra: ");scanf("%f",&valor);

    centavos = valor - ((int) valor);


    for (int i = valor; i > 0; i--)
    {
        if(checkMult(i,3)==0){
            dummy = i;
            break;
        }
    }
    
    parcelas = dummy/3;
    entrada = ( (valor) - dummy) + parcelas;

    printf("Haverá uma entrada de %.2f e duas parcelas de %i\n",entrada,parcelas);

    return 0;
}