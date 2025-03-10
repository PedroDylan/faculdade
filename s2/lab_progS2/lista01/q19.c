#include <stdio.h>

void linha(char tile,int num){
    int i;
    for(i=1; i <= num; i++){
        putchar(tile);
    }
    putchar('\n');
}

void printRetangulo(char tile, int num){
    
    linha(tile,num);
    for(int i = 0; i<num ; i++){
        printf("%c%5c\n",tile,tile);
    }
    linha(tile,num);

}

void printElipse(char tile, int num){
    printf("  ") ;linha(tile,3);
    printf("%2c%5c\n",tile,tile);

    for(int i =0; i<num; i++){
        printf("%c%7c\n",tile,tile);
    }
    printf("%2c%5c\n",tile,tile);
    printf("  ") ;linha(tile,3);
}

void printSeta(char tile, int num){
    printf("  "); linha(tile,1);
    printf(" "); linha(tile,3);
    linha(tile,5);

    for(int i =0; i < num ; i++){
        printf("  ");linha(tile,1);
    }
}

void printLosango(char tile){
    printf("%5c\n",tile);
    printf("%4c%2c\n",tile,tile);
    printf("%3c%4c\n",tile,tile);
    printf("%2c%6c\n",tile,tile);
    printf("%c%8c\n",tile,tile);
    printf("%2c%6c\n",tile,tile);
    printf("%3c%4c\n",tile,tile);
    printf("%4c%2c\n",tile,tile);
    printf("%5c\n",tile);
}

int main(){
    char tile='*';

    printRetangulo(tile,6);
    printElipse(tile,5);
    printSeta(tile,6);
    printLosango(tile);
    
    return 0;
}