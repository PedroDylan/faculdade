#include <stdio.h>

int calcAltura(int alturaInicial, int taxa ,int anos){

    return (alturaInicial + taxa*anos);
}




int main(){

    int altInicialA, taxaA, altInicialB, taxaB;

    puts("Insira a altura inicial do indivíduo A: "); scanf("%i",&altInicialA);
    puts("Insira a taxa de crescimento do indivíduo A : "); scanf("%i",&taxaA);
    puts("Insira a altura inicial do indivíduo B: "); scanf("%i",&altInicialB);
    puts("Insira a taxa de crescimento do indivíduo B : "); scanf("%i",&taxaB);




    for(int anos = 0; anos <150; anos++){
        if (calcAltura(altInicialA,taxaA,anos) == calcAltura(altInicialB,taxaB,anos))
        {
            printf("Eles terão a mesma altura após %i anos\n",anos);
            break;
        }
        
    }


    return 0;
}