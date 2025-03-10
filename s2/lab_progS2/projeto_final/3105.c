// Esse código já é capaz de recortar pedaços delimitados
// de pontos de uma matriz dada 
// Ele ainda precisa resolver o problema das bordas

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Matrix
{
    int lin;
    int col;
    int lum;
    int* linhas;
};

void mallocMatrix(struct Matrix*);
void generateMatrix(struct Matrix* );
void printMatrix(struct Matrix* );
int generateRandomPoint(struct Matrix *);
void createSection(struct Matrix *, struct Matrix *, int );
void findLine(struct Matrix *, int , int , int *);
void findSection(struct Matrix *, struct Matrix * ,int , int );

int main(int argc, char* argv[]){
    if (argc != 4)
    {
        puts("Número errado de inputs.");
        exit(1);
    }

    struct Matrix matrix;
    struct Matrix section;
    struct Matrix *p_matrix = &matrix;
    struct Matrix *p_section =&section;
    int sizeSection = 5;
    int ponto;

    matrix.lin = atoi(argv[1]);
    matrix.col = atoi(argv[2]);
    matrix.lum = atoi(argv[3]);

    mallocMatrix(p_matrix);
    if (!matrix.linhas)
    {
        puts("Memória não alocada.");
        exit(2);
    }
    generateMatrix(p_matrix);
    printMatrix(p_matrix);
    
    ponto = generateRandomPoint(p_matrix);
    printf("posicao: %i\n",ponto);


    createSection(p_matrix,p_section,sizeSection);
    if(!p_section->linhas){
        puts("memória não alocada.");
        exit(3);
    }


    findSection(p_matrix, p_section, ponto, sizeSection);
    puts("Section: ");
    printMatrix(p_section);


    free(p_matrix->linhas);
    return 0;
}

void mallocMatrix(struct Matrix *p_m){
    int total = (p_m->lin)*(p_m->col)*sizeof(int);
    
    (p_m->linhas) = (int*) malloc (total);
}

void generateMatrix(struct Matrix *p_m){
    srand(time(NULL));
    
    int total = (p_m->col)*(p_m->lin);

    for (int i = 0; i < total; i++)
    {
        p_m->linhas[i] = rand()%(p_m->lum);
    }
    
}

void printMatrix(struct Matrix *p_m){
    int total = (p_m->lin)*(p_m->col);
    
    for (int i = 0; i < total; i++)
    {
        if (i%p_m->col==0)
        {
            printf("\n");
        }

        printf("%.2i ",p_m->linhas[i]);
    }
    printf("\n\n");
}

int generateRandomPoint(struct Matrix *p_m){
    int total = (p_m->col)*(p_m->lin);
    return rand()%total;
}

void createSection(struct Matrix *p_m, struct Matrix *p_mr, int r_size){

    p_mr->col= r_size;
    p_mr->lin= r_size;
    p_mr->lum= p_m->lum;

    mallocMatrix(p_mr);
}

void findLine(struct Matrix *p_m, int ponto, int sizeS, int *line){
    for (int i = 0; i < sizeS; i++)
    {
        *(line+i) = p_m->linhas[ponto+i];
    }
}

void findSection(struct Matrix *p_m, struct Matrix *p_mr ,int ponto, int sizeS){
    for (int i = 0; i <sizeS; i++)
    {
        findLine(p_m, ponto+i*p_m->col, sizeS, p_mr->linhas+i*sizeS);
    }
}