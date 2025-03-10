#include <stdio.h>
#define SIZE 50

void conta_string(char*, int*);

int main(){
    
    char string[SIZE];
    int counter = 0;
    int* p_counter = &counter;

    puts("Insira a string: ");
    scanf("%s",string);

    conta_string(string, p_counter);
    
    printf("%i\n",*p_counter);
    
    
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