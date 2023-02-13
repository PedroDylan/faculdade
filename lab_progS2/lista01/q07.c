#include <stdio.h>

int main(){
    int horas, minutos, segundos;
    int total;

    puts("Insira o número de horas: ");
    scanf("%i",&horas);
    
    puts("Insira o número de minutos: ");
    scanf("%i",&minutos);
    
    puts("Insira o número de segundos: ");
    scanf("%i",&segundos);
    
    total = segundos + 60*minutos + 3600*horas;

    printf("O total de segundos é: %i\n",total);
    
    return 0;
}