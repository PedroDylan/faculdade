#include <stdio.h>

int main(){
    float valorDia = 50.25, valorLiquido, gratificacao;
    int dias, imposto = 10;

    puts("Insira a quantidade de dias trabalhados: ");
    scanf("%i",&dias);
    
    if (dias <= 10)
    {
        gratificacao = 0;
    } else if(10 < dias <= 20){
        gratificacao = valorDia*dias*(0.2);
    } else if (30 <= dias)
    {
        gratificacao = valorDia*dias*(0.3);
    }
    
    valorLiquido = valorDia*dias + gratificacao;
    valorLiquido = valorLiquido - valorLiquido*imposto/100;

    printf("O valor final recebido é: %.2f\n", valorLiquido);   
    
    
    return 0;
}