#include <stdio.h>
#define SIZE 100

int checkMult(int dividendo, int divisor){
    if( dividendo%divisor==0 && divisor!=0 && dividendo!=0){
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

int somatorio(int array[SIZE]){
    int acc = 0;

    for(int i = 0; i<SIZE; i++){
        acc+=array[i];
    }

    return acc;
}




int main(){

    int menor,maior,index=0;
    int pares[SIZE] = {0};
    long soma;

    puts("Insira o limite inferior: ");
    scanf("%i",&menor);
    puts("Insira o limite superior: ");
    scanf("%i",&maior);

    if (menor > maior)
    {
        troca(menor,maior);
    }

    for(int i=menor; i<=maior; i++){
        if(checkMult(i,2)==0){
            pares[index] = i;
            index++;
        }
    }

    puts("Os pares do intervalo são: ");
    printArray(pares);

    soma=somatorio(pares);

    
    printf("A soma dos pares no intervalo é : %li\n",soma);
    return 0;
}