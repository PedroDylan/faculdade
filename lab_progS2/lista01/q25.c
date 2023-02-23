#include <stdio.h>

int main(){
    int total;
    int horas, minutos, segundos;

    puts("Insira o total de segundos: ");scanf("%i",&total);

    horas = total/3600;
    minutos = (total - horas*3600)/60;
    segundos = total - horas*3600 - minutos*60;

    printf("%i horas, %i minutos e %i segundos\n", horas, minutos, segundos);
    
    
    
    
    return 0;
}