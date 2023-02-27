#include <stdio.h>

long Fibonacci(int valor){
    if(valor > 2){
        return (Fibonacci(valor-1)+Fibonacci(valor-2));
    } else {
        return 1;
    }
}

int main(){

    for(int i=1 ; i<=20 ; i++){
        printf("%li\n",Fibonacci(i));
    }

    return 0;
}