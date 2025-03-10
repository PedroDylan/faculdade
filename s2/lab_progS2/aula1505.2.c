#include <stdio.h>
#include <stdlib.h>

void somar(int a, int b);
void subtrair(int a, int b);
void multiplicar(int a, int b);
void dividir(int a, int b);

int main(int argc, char* argv[]){
    
    void (*pFunc[])() = {&somar, &subtrair, &multiplicar, &dividir};
    int a,b;


    if (argc != 2)
    {
        puts("Quantidade errada de inputs.");
        exit(1);
    }

    puts("insira o primeiro termo: ");scanf("%i",&a);
    puts("insira o segundo termo: ");scanf("%i",&b);    
    
    int codigo = atoi(argv[1]);
    (*pFunc[codigo])(a,b);
    
    return 0;
}

void somar(int a, int b){
    printf("%i\n",a+b);
}

void subtrair(int a, int b){
    printf("%i\n",a-b);
}

void multiplicar(int a, int b){
    printf("%i\n",a*b);
}

void dividir(int a, int b){
    if(b!=0){
    printf("%i\n",a/b);
    }
}