#include <stdio.h>
#include <string.h>
#define SIZE 50

int main(){
    
    char str1[SIZE], str2[SIZE];

    puts("Insira a primeira string: ");
    scanf("%s",str1);
    puts("Insira a segunda string: ");
    scanf("%s",str2);


    if (strcmp(str1,str2)){
        puts("Strings diferentes");
    } else {
        puts("Strings Iguais");
    }

    return 0;
}