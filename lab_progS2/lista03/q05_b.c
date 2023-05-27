#include <stdio.h>
#include <string.h>

void concat(char *dest, char *src);

int main(){
    
    char primeira[51], segunda[51];

    puts("Insira a primeira metade da string");
    scanf("%s",primeira);
    puts("Insira a segunda metade da string");
    scanf("%s",segunda);

    //Processamento
    concat(primeira,segunda);
    //

    puts("String final.");
    printf("%s\n",primeira);
    
    return 0;
}

void concat(char *dest, char *src){

    int counterD=0;
    int i=0;
    while (*(dest+i)!='\0')
    {
        counterD++;
        i++;
    };

    int counterS=0;
    int j=0;
    while (*(src+j)!='\0')
    {
        counterS++;
        j++;
    }

    for (int i = 0; i < counterS; i++)
    {
        *(dest+counterD+i) = *(src+i);
    }
}