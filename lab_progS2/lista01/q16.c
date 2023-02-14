#include <stdio.h>

int main(){
    float horaAula, imposto, sBruto ,sLiquido;
    int horasTrabalhadas;
    
    puts("Insira a quantidade de horas trabalhadas: ");
    scanf("%i",&horasTrabalhadas);

    puts("Insira o valor da hora aula: ");
    scanf("%f",&horaAula);
    
    puts("Insira o desconto do INSS : ");
    scanf("%f",&imposto);

    sBruto = horasTrabalhadas*horaAula;
    sLiquido = sBruto - sBruto*imposto/100;

    printf("O salário bruto é: %.2f, e o líquido: %.2f\n",sBruto, sLiquido);






    
    return 0;
}