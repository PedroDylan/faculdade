#include <stdio.h>

void conta_string(char* , int* );

int main(){

    int size = 50;
    char primeira[size + 1], segunda[size + 1];
    char resultado[2*size + 1];
    int num1, num2;
    int *p_num1 = &num1, *p_num2 = &num2;

    puts("Insira a primeira string: ");
    scanf("%s",primeira);
    puts("Insira a segunda string: ");
    scanf("%s",segunda);

    conta_string(primeira, p_num1);
    conta_string(segunda, p_num2);

    for (int i = num1, j = 0; i < num1+num2, j<num2; i++,j++)
    {
        *(primeira+i) = *(segunda + j); 
    }
    
    printf("%s\n",primeira);


    return 0;
}

void conta_string(char* p_string, int* p_result){
    
    int result = 0;

    int i = 0;
    while (*(p_string+i)!='\0')
    {
        result++;
        i++;
    }

    *p_result = result;
    
}