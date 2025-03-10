#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimirVetor(unsigned int*, int );

int main(){
    
    int size;

    puts("Insira o tamanho do vetor: ");
    scanf("%i",&size);

    //alocação dinâmica de memória
    unsigned int *pointer;
    pointer = malloc(size * sizeof(unsigned int));

    if(!pointer){
        puts("Não existe memória disponível. Te vira.");
        exit(1);
    }

    //receber os elementos do vetor
    puts("Insira os elementos do vetor.");
    for(int i =0; i<size; i++){
        scanf("%i",(pointer + i));
    }
    

    //imprimir o vetor
    imprimirVetor(pointer , size);

    //liberando a memória alocada após a execução do programa
    free(pointer);
    
    return 0;
}

void imprimirVetor(unsigned int *p, int size){

    for(int i =0; i<size; i++){
        printf("[%p] %u\n", p+i , *(p+i));
    }

}