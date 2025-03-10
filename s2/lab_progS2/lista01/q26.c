#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    float x1,y1,x2,y2,distance;


    puts("Insira a primeira coordenanda X: ");
    scanf("%f",&x1);
    puts("Insira a primeira coordenanda Y: ");
    scanf("%f",&y1);
    puts("Insira a segunda coordenanda X: ");
    scanf("%f",&x2);
    puts("Insira a segunda coordenanda Y: ");
    scanf("%f",&y2);

    distance = sqrt( pow(x2-x1,2) +pow(y2-y1,2));

    printf("A distância é : %.2f\n",distance);
    
    
    
    
    return 0;
}