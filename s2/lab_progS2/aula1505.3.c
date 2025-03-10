#include <stdio.h>
#include <stdlib.h>

void somar(int a, int b, int *pR);
void subtrair(int a, int b, int *pR);
void multiplicar(int a, int b, int *pR);
void dividir(int a, int b, int *pR);
void calcular(void (*pf)(), int a, int b, int *pR );

typedef void (*Func)();

int main(int argc, char* argv[]){
    
    Func v[] = {&somar, &subtrair, &multiplicar, &dividir};

    if (argc != 4)
    {
        puts("Quantidade errada de inputs.");
        exit(1);
    }

    int op = atoi(argv[1]);
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);
    int r;
    int *pr = &r;

    if(op < 0 || op >3){
        puts("Operação não inicializada.");
        exit(2);
    }

    calcular(v[op],a,b,pr);

    printf("Resultado: %i\n",r);

    
    return 0;
}

void somar(int a, int b, int *pR){
    *pR = a+b;
}

void subtrair(int a, int b, int *pR){
    *pR = a-b;
}

void multiplicar(int a, int b, int *pR){
    *pR = a*b;
}

void dividir(int a, int b, int *pR){
    *pR = a/b;
}

void calcular(void (*pf)(), int a, int b, int *pR){
    (*pf)(a,b,pR);
}