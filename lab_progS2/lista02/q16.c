#include <stdio.h>

int checkMult(int dividendo, int divisor){
    if( dividendo%divisor==0 && divisor!=0 && dividendo!=0){
        return 0;
    } else {
        return 1;
    }
}

int main(){

    int acc3=0, acc5=0;

    for (int i = 0; i <= 200; i++){
        if( i <= 100 && checkMult(i,3) == 0){
            acc3 += i;
        }  
        if(100<i && i<=200 && checkMult(i,5)==0){
            acc5 += i;
        }
    }

    printf("A soma dos múltiplos de 3 no intervalo [0,100] é : %i\n",acc3);
    printf("A soma dos múltiplos de 5 no intervalo ]100,200] é : %i\n",acc5);

    
    
    return 0;
}