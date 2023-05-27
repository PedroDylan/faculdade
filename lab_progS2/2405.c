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

int main(int argc, char* argv[]){
    
    if (argc != 4)
    {
        puts("Número errado de inputs.");
        exit(1);
    }

    struct Matrix matrix;
    struct Matrix *p_matrix = &matrix;

    matrix.lin = atoi(argv[1]);
    matrix.col = atoi(argv[2]);
    matrix.lum = atoi(argv[3]);

    // matrix.linhas = (int*) malloc(matrix.lin*matrix.col*sizeof(int)); 
    mallocMatrix(p_matrix);

    if (!matrix.linhas)
    {
        puts("Memória não alocada.");
        exit(2);
    }
    
    generateMatrix(p_matrix);
    printMatrix(p_matrix);

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
    printf("\n");
}
