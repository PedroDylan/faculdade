#include <stdio.h>

int main(){
    
    int size = 30;
    char array[size+1];
    char copia[size+1];

    puts("Insira a string: ");
    scanf("%s",array);

    for (int i = 0; i < size+1; i++)
    {
        *(copia + i) = *(array + i);
    }
    
    printf("%s\n",copia);
    
    
    return 0;
}