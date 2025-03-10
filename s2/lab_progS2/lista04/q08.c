#include <stdio.h>
#define SIZE 50

void encontrar (char* string, char busca, int* p_resultado);

int main(){
    
    char string[SIZE];
    char busca;
    char* p_busca = &busca;
    int encontrado;
    int* p_encontrado = &encontrado;

    puts("Insira a string: ");
    scanf("%s",string);
    
    puts("Insira o caractere a ser buscado: ");
    scanf(" %c",p_busca);

    encontrar(string, busca, p_encontrado);
    
    if(encontrado){
        puts("Caractere encontrado");
    } else {
        puts("Caractere não encontrado");
    }
    
    return 0;
}

void encontrar (char* string, char busca, int* p_resultado){
    int i = 0;
    int resultado;

    while (*(string+i)!='\0')
    {
        if(*(string+i)==busca){
            resultado = 1;
            break;
        } else {
            resultado = 0;
        }
        
        i++;
    }
    
    *p_resultado = resultado;

}