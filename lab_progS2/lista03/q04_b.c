#include <stdio.h>
#include <string.h>
#define SIZE 50

int compare (char *p1, char *p2, int size);

int main(){

    char str1[SIZE], str2[SIZE];
    char *p1, *p2;

    p1 = str1;
    p2 = str2;

    puts("Insira a primeira string: ");
    scanf("%s", str1);
    puts("Insira a segunda string: ");
    scanf("%s", str2);

    if(compare(p1,p2,SIZE)){
        puts("Strings diferentes");
    } else {
        puts("strings iguais");
    }

    return 0;
}

int compare (char *p1, char *p2, int size){
    int iguais = 0; 

    for (int i = 0; i <size; i++)
    {
        if ( *(p1+i) != *(p2+i))
        {
            iguais = 1;
            break;
        }
        
    }
    
    return iguais;

}