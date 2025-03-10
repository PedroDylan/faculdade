//Aluno: Pedro Dylan Freires Fernandes
//Matrícula: 20222045050220
//Avaliação 4: Trabalho Final
//04.505.23 - 2023.1 - Prof. Daniel Ferreira
//Compilador : gcc (Ubuntu 11.3.0-1ubuntu1~22.04.1) 11.3.0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SUBIMAGEWIDTH 100
#define SUBIMAGEHEIGHT 100

struct pgm{
	int tipo;
	int c;
	int r;
	int mv;
	unsigned char *pData;
};

void readPGMImage(struct pgm *, char *);
void writePGMImage(struct pgm *, char *);
void applyAverageFilter(struct pgm *);
void generateSubImages(struct pgm *, int , const char *) ;

int main(int argc, char *argv[]){

    struct pgm img;

	if (argc!=4){
		printf("Formato: \n\t %s <imagemEntrada.pgm> <Número de imagens> <Diretório de saída>\n",argv[0]);
		exit(1);
	}

    readPGMImage(&img,argv[1]);
    
    generateSubImages(&img,atoi(argv[2]),argv[3]);

    return 0;
}

void readPGMImage(struct pgm *pio, char *filename){

	FILE *fp;
	char ch;

	if (!(fp = fopen(filename,"r"))){
		perror("Erro.");
		exit(1);
	}

	if ( (ch = getc(fp))!='P'){
		puts("A imagem fornecida não está no formato pgm");
		exit(2);
	}
	
	pio->tipo = getc(fp)-48;
	
	fseek(fp,1, SEEK_CUR);

	while((ch=getc(fp))=='#'){
		while( (ch=getc(fp))!='\n');
	}

	fseek(fp,-1, SEEK_CUR);

	fscanf(fp, "%d %d",&pio->c,&pio->r);
	if (ferror(fp)){ 
		perror(NULL);
		exit(3);
	}	
	fscanf(fp, "%d",&pio->mv);
	fseek(fp,1, SEEK_CUR);

	pio->pData = (unsigned char*) malloc(pio->r * pio->c * sizeof(unsigned char));

	switch(pio->tipo){
		case 2:
			puts("Lendo imagem PGM (dados em texto)");
			for (int k=0; k < (pio->r * pio->c); k++){
				fscanf(fp, "%hhu", pio->pData+k);
			}
		break;	
		case 5:
			puts("Lendo imagem PGM (dados em binário)");
			fread(pio->pData,sizeof(unsigned char),pio->r * pio->c, fp);
		break;
		default:
			puts("Não está implementado");
	}
	
	fclose(fp);

}

void writePGMImage(struct pgm *pio, char *filename){
	FILE *fp;
	char ch;

	if (!(fp = fopen(filename,"wb"))){
		perror("Erro.");
		exit(1);
	}

	fprintf(fp, "%s\n","P5");
	fprintf(fp, "%d %d\n",pio->c, pio->r);
	fprintf(fp, "%d\n", 255);

	fwrite(pio->pData, sizeof(unsigned char),pio->c * pio->r, fp);

	fclose(fp);

}

void applyAverageFilter(struct pgm *pio) {
    int total = (pio->c)*(pio->r);
    int *filteredMatrix = calloc(total,sizeof(int)); // Matriz filtrada, inicializada com 0s
    
    for (int i = 0; i < pio->r; i++) {
        for (int j = 0; j < pio->c; j++) {
            int sum = 0;
            int count = 9;
            
            // Calcula a soma dos elementos na janela 3x3 em torno do elemento atual
            //Loops encadeados indo de -1 a 1 (3 elementos) 
            for (int m = -1; m <= 1; m++) {
                for (int n = -1; n <= 1; n++) {
                    //checagem para fazer o tratamento de bordas evitando pixels vazios
                    if (i + m >= 0 && i + m < pio->r && j + n >= 0 && j + n < pio->c) {
                        //usando função (x,y) = (x,0) + LIN*(0,y)
                        sum += *(pio->pData + (i + m) + (pio->r)*(j + n));
                    }
                }
            }
            
            // Calcula a média e atualiza o elemento central da janela na matriz filtrada
            if (count > 0) {
                filteredMatrix[i+j*(pio->r)]= sum / count;
            }
        }
    }
    
    // Atualiza a matriz original com os valores filtrados
    for (int i = 0; i < total; i++) {
        *(pio->pData + i) = filteredMatrix[i];
    }
}

void generateSubImages(struct pgm *image, int numSubImages, const char *outputDir) {
    srand(time(NULL));

    for (int i = 0; i < numSubImages; i++) {
        //Gerando números aleatórios de colunas e linhas
        //para encontrar a coordenada da subimagem na imagem
        int x = rand() % (image->c - SUBIMAGEWIDTH + 1);
        int y = rand() % (image->r - SUBIMAGEHEIGHT + 1);

        struct pgm subImage;
        struct pgm* p_subImage;
        subImage.c = SUBIMAGEWIDTH;
        subImage.r = SUBIMAGEHEIGHT;
        int total = subImage.c * subImage.r;
        subImage.pData = (unsigned char *) malloc(total*sizeof(unsigned char));

        for (int i = 0; i < subImage.r; i++)
        {
            for (int j = 0; j < subImage.c; j++)
            {
                //calculo similar ao usado na função do filtro
                int index = (x + i) * (image->c) + (y + j);
                //Tratamento de bordas
                if (x + i < (image->r) && y + j < (image->c))
                {
                    subImage.pData[i * subImage.c + j] = image->pData[index]; // Copia os elementos da seção quadrada para a submatriz
                }
                else
                {
                    subImage.pData[i * subImage.c + j] = 0; // Define como 0 se estiver fora dos limites da matriz original
                }
            }
        }

        applyAverageFilter(&subImage);

        char filename[100+1];
        sprintf(filename, "%s/subimage%d.pgm", outputDir, i + 1);
        writePGMImage(&subImage, filename);
    }
}


