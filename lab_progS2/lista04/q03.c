#include <stdio.h>

int main(){
    
    int num, check = 10;
    int *pnum = &num, *pcheck = &check ;

    do
    {
        puts("insira um número: ");
        scanf("%i",pnum);

        if (*pnum < *pcheck)
        {
            *pcheck = *pnum;
        }

        printf("%i\n",*pcheck);
        
    } while (*pnum != 0);
    
    printf("%i\n",*pcheck);
    
    return 0;
}