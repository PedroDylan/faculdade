#include <stdio.h>
#include <stdlib.h>

void somar(int n1, int n2, int* nr);
void multiplicar(int n1, int n2, int* nr);
void calcular(void (*p_f)(), int n1, int n2, int* p_r);

int main(int argc, char* argv[]){
    
    if(argc != 4){
        puts("Quantidade errada de inputs.");
        exit(1);
    }
    //
    int resultado;
    int operacao = atoi(argv[1]);
    int num1 = atoi(argv[2]);
    int num2 = atoi(argv[3]);
    //
    
    void (*v[])() = {somar,multiplicar};

    calcular(v[operacao],num1,num2,&resultado);
    printf("O resultado é: %i\n",resultado);

    return 0;
}

void calcular(void (*p_f)(), int n1, int n2, int* p_r){
    (*p_f)(n1,n2,p_r);
}

void somar(int n1, int n2, int* nr){
    *nr = n1+n2;
}

void multiplicar(int n1, int n2, int* nr){
    *nr = n1*n2;
}