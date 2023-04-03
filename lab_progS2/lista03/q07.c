#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float media_arit(int a, int b, int c);
float media_geo(int a, int b, int c);

int main(){
    
    int a,b,c;
    float media_a, media_g;

    srand(time(NULL));

    a = rand()%19;
    b = rand()%19;
    c = rand()%19;

    media_a = media_arit(a,b,c);
    media_g = media_geo(a,b,c);

    printf("Os valores são: %i %i %i\n",a,b,c);

    printf("A média aritmética é : %f\n", media_a);

    printf("A média geométrica é : %f\n",media_g);

    return 0;
}

float media_arit(int a, int b, int c){
    return ((float) a + b + c)/3;
}

float media_geo(int a, int b, int c){
    int prod;

    prod = a*b*c;

    return pow((float) prod,0.5);
}