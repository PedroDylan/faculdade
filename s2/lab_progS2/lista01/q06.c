#include <stdio.h>

float calcPeso(float altura, char sexo){
    float pesoIdeal;

    if (sexo != 0)
    {
        pesoIdeal = 62.1*altura - 44.7;
    } else {
        pesoIdeal = 72.7*altura - 58;
    }
    return pesoIdeal;
    
}



int main(){
    float altura,pesoIdeal;
    char sexo;

    printf("Insira sua altura: ");
    scanf("%f",&altura);
    printf("Você é Homem(0) ou Mulher(1)?\n");
    scanf(" %c",&sexo);
    
    pesoIdeal = calcPeso(altura,sexo);

    printf("Seu peso ideal é: %.2f\n", pesoIdeal );
    
    return 0;
}