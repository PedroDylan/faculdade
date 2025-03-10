#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

struct node
{
    int valor;
    struct node* proximo;
};

void gerarValor(struct node* , int );
struct node acharNode(struct node* , int );
void printNode(struct node* , int );

int main(){
    
    int pesquisa;
    struct node result;
    struct node n1, n2, n3, n4, head;
    head.proximo = &n1;
    n1.proximo = &n2;
    n2.proximo = &n3;
    n3.proximo = &n4;
    n4.proximo = NULL;

    srand(time(NULL));
    gerarValor(&n1,MAX);
    gerarValor(&n2,MAX);
    gerarValor(&n3,MAX);
    gerarValor(&n4,MAX);
    //
    puts("Insira o node a ser pesquisado.");
    scanf("%i",&pesquisa);
    //
    result = acharNode(&head, pesquisa);
    printf("Valor do node pesquisado: %i\n",result.valor);
    //
    printNode(&n1,1);
    printNode(&n2,2);
    printNode(&n3,3);
    printNode(&n4,4);

    return 0;
}

void gerarValor(struct node* p_node, int max){
    (p_node->valor) = rand()%max + 1;
}

struct node acharNode(struct node* head, int pesquisa){

    int dummy = 0;
    struct node result = *(head);

    for(  ;result.proximo != NULL && dummy < pesquisa; result = *(result.proximo)){
        dummy++;
    }

    return result;
}

void printNode(struct node* p_node, int posicao){

    printf("Valor de n%i: %i\n",posicao,p_node->valor);

}