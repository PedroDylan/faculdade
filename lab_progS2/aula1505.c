#include <stdio.h>

void imprimirNum(int );

int main(){
    int n;
    void (*pFunc)(int);

    pFunc = &imprimirNum;

    puts("Insira um inteiro: "); scanf("%i",&n);

    (*pFunc)(n);

    return 0;
}

void imprimirNum(int n){
    printf("%i\n",n);
}