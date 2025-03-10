#include <stdio.h>

int main(){
    float celsius, fahrenheit;

    puts("Insira a temperatura em Célsius: ");
    scanf("%f",&celsius);

    fahrenheit = (9*celsius+160)/5;

    printf("A temperatura em fahrenheit é: %.2f\n",fahrenheit);
    
    return 0;
}