#include <stdio.h>
#include <string.h>

int main(){
    
    char primeira[51], segunda[51];

    puts("Insira a primeira metade da string");
    scanf("%s",primeira);
    puts("Insira a segunda metade da string");
    scanf("%s",segunda);
    
    strcat(primeira, segunda);

    puts("String final.");
    printf("%s\n",primeira);
    
    return 0;
}