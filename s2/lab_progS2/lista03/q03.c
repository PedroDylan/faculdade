#include <stdio.h>
#define SIZE 50

int conta(char *p, int size);

int main(){
    
    char string[SIZE];
    char *p_str;
    
    p_str = string; 

    puts("Insira uma string: ");
    scanf("%s",string);

    printf("A string tem %i caracteres\n", conta(p_str,SIZE));

    return 0;
}

int conta(char *p, int size){
    int numero = 0;

    for (int i = 0; i < size; i++)
    {
        if (*(p+i) == '\0')
        {
            break;
        }
        numero++;
    }

    return numero;    
}