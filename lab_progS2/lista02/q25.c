#include <stdio.h>
#include <math.h>

float termo(int num){
    return 4/((2*num+1)*pow((-1),num));
}

float soma(int valor){
    float resultado = 0;

    for (int i = 0; i < valor; i++)
    {
        resultado += termo(i);
    }

    return resultado;

}

int main(){

    int termo;

    puts("Até qual termo você deseja somar? : ");
    scanf("%i",&termo);
    
    printf("%f\n",soma(termo));
    
    
    return 0;
}