#include <stdio.h>
#define SIZE 200

void printArray(int array[SIZE]){
    puts("Array de números: ");
    for(int i=0; i<SIZE; i++){
        if( array[i]==0 ){
            continue;
        } else {
        printf("%i\n",array[i]);
        }
    }    
}

void sort(int array[SIZE]){
    auto int i,j,dummy;
    /*Organizando o array*/
    for (j = 1; j < SIZE; j++)
    {
        for (i = 0; i < SIZE - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                dummy = array[i];
                array[i]=array[i+1];
                array[i+1]=dummy;
            }
        }
    }

}

int main(){

    int termos[SIZE] = {0} ;
    int input,controle=0;

    while (input !=0)
    {
        puts("Insira um número inteiro: ");
        scanf("%i",&input);      

        termos[controle] = input;
        sort(termos);

        printf("O maior termo foi %i\n",termos[-1]);
        printf("O menor termo foi %i\n",termos[0]);

        printArray(termos);

        controle++;
    }

   
   
    return 0;
}