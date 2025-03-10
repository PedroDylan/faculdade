#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int checkFour(int valor){
    if( valor%4==0 ){
        return 0;
    } else {
        return 1;
    }
}

void troca(int a, int b){
    int dummy;

    dummy = a;
    a=b;
    b=dummy;
}

void printArray(int array[SIZE]){
    for(int i=0;i<SIZE;i++){
        if(array[i]==0){
            continue;
        } else {
        printf("%i\n",array[i]);
        }
    }    
}

int main(){

    int multiplos[SIZE] = {0};
    int quadrados[SIZE] = {0};
    int menor, maior;
    int index=0;

    puts("Insira o limite inferior: ");
    scanf("%i",&menor);
    puts("Insira o limite superior: ");
    scanf("%i",&maior);
    
    if (menor > maior)
    {
        troca(menor,maior);
    }

    for(int i = menor; i<= maior; i++){
        if(checkFour(i)==0){
            multiplos[index] = i;
            index++;
        }
    }
    
    puts("Múltiplos de 4 no intervalo: ");
    printArray(multiplos);

    for(int i = 0; i<SIZE; i++){
        quadrados[i] = (multiplos[i]*multiplos[i]);
    }

    puts("Quadrados dos múltiplos de 4: ");
    printArray(quadrados);

    return 0;
}