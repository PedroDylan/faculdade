#include <stdio.h>
#define SIZE 50

int busca(char string[], char carac, int size);

int main(){

    char carac;
    char string[SIZE];

    puts("Insira o caractere:");
    carac = getchar();    
    puts("Insira a string: ");
    scanf("%s",string);

    
    
    if (busca(string,carac,SIZE)==1)
    {
        puts("Caractere encontrado");
    } else 
    {
        puts("Caractere não encontrado");
    }
    


    return 0;
}

int busca(char string[], char carac, int size){
    int resultado = 0;
    
    for (int i = 0; i < size; i++)
    {
        if (string[i]==carac)
        {
            resultado=1;
            break;
        }
        
    }
    return resultado;
}