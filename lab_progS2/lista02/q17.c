#include <stdio.h>

float celciusToFahrenheit(int celcius){
    return (1.8*celcius + 32);
}


int main(){
    
    printf("10°C _____ %.2f°F\n",celciusToFahrenheit(10.0));
    printf("20°C _____ %.2f°F\n",celciusToFahrenheit(20.0));
    printf("30°C _____ %.2f°F\n",celciusToFahrenheit(30.0));
    printf("40°C _____ %.2f°F\n",celciusToFahrenheit(40.0));
    printf("50°C _____ %.2f°F\n",celciusToFahrenheit(50.0));
    printf("60°C _____ %.2f°F\n",celciusToFahrenheit(60.0));
    printf("70°C _____ %.2f°F\n",celciusToFahrenheit(70.0));
    printf("80°C _____ %.2f°F\n",celciusToFahrenheit(80.0));
    printf("90°C _____ %.2f°F\n",celciusToFahrenheit(90.0));
    printf("100°C ____ %.2f°F\n",celciusToFahrenheit(100.0));
    
    
    
    
    
    return 0;
}