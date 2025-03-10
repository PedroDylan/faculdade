#include <stdio.h>

void reverse(char* string);

int main(){
    
    char string[51];

    puts("Insira a string.");
    scanf("%s",string);
    
    reverse(string);

    return 0;
}

void reverse(char* string){

    int i=0;
    int counter=0;
    while (*(string+i)!='\0')
    {
        counter++;
        i++;
    };

    puts("A string em reverso é: ");
    for (int i = counter; i >= 0; i--)
    {
        printf("%c",*(string+i));
    }
    printf("\n");
}