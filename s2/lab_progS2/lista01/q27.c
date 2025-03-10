#include <stdio.h>

#include <math.h>

int main(){
    
    float num1, num2, num3;
    float mediaA, mediaG;

    printf("Insira o primeiro número: "); scanf("%f",&num1);
    printf("Insira o segundo número: "); scanf("%f",&num2);
    printf("Insira o terceiro número: "); scanf("%f",&num3);

    mediaA = (num1+num2+num3)/3;
    mediaG = pow(num1*num2*num3,0.5);

    printf("A média aritmética é %.3f e a geométrica é %.3f\n",mediaA,mediaG);
    
    return 0;
}