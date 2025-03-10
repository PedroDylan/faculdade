#include <stdio.h>
#include <math.h>

int main(){
    
    float raio, pi = 3.14159;

    puts("Insira o raio da circunferência : ");
    scanf("%f",&raio);

    printf("O diâmetro é : %.2f\n",2*raio);
    printf("A circunferência é : %.2f\n",2*raio*pi);
    printf("A área é : %.2f\n",pi*raio*raio);

    
    
    
    
    
    
    
    return 0;
}