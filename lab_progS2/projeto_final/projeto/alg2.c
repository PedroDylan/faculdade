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

void saveCoordinates(char *fileName, int **coordinates, int t);
double calculateMSE(struct pgm image1, struct pgm image2) ;
void readPGMImage(struct pgm *pio, char *filename);

int main(int argc, char* argv[]){
    
    struct pgm image;
    struct pgm* p_image= &image;

    if (argc!=5){
		printf("Formato: \n\t %s <Diretório de Entrada> <imagemEntrada.pgm> <Número de subimagens> <output.txt> \n",argv[0]);
		exit(1);
	}
    
    //char subImagesDirectory = (argv[1]);
    //char imageFileName = (argv[2]);
    int numSub = atoi(argv[3]);
    readPGMImage(p_image,argv[2]);
    
    // Alocar matriz para as coordenadas
    int **coordinates = (int **)malloc(numSub * sizeof(int *));
    for (int i = 0; i < numSub; i++) {
        coordinates[i] = (int *)malloc(2 * sizeof(int));
    }

    for (int k = 0; k < numSub; k++) {
        // Construir o nome do arquivo da sub-imagem
        char subImageFileName[100];
        sprintf(subImageFileName, "%s/subimage%d.pgm", argv[1] , k + 1);

        // Ler a sub-imagem
        struct pgm subImage;
        struct pgm* p_subImage= &subImage;

        readPGMImage(p_subImage,subImageFileName);
        
        double minMSE = -1;
        int minX = -1;
        int minY = -1;

        // Realizar a busca na imagem fornecida pelo usuário
        for (int i = 0; i <= image.r - subImage.r; i++) {
            for (int j = 0; j <= image.c - subImage.c; j++) {
                struct pgm currentImage;
                
                currentImage.pData = (unsigned char*)malloc(subImage.r* subImage.c * sizeof(unsigned char));
                for (int a = 0; a < subImage.r; a++)
                {
                    currentImage.pData[a] = (image.pData[i + a + j*(image.r)]);
                }

                double mse = calculateMSE(currentImage, subImage);

                if (minMSE == -1 || mse < minMSE) {
                    minMSE = mse;
                    minX = j;
                    minY = i;
                }
            }
        }

        // Salvar as coordenadas
        coordinates[k][0] = minX;
        coordinates[k][1] = minY;
    }

    saveCoordinates(argv[4], coordinates, numSub);


    return 0;
}

void saveCoordinates(char *fileName, int **coordinates, int t) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo.\n");
        exit(1);
    }

    for (int i = 0; i < t; i++) {
        fprintf(file, "Sub-imagem %d: (%d, %d)\n", i + 1, coordinates[i][0], coordinates[i][1]);
    }

    fclose(file);
}

double calculateMSE(struct pgm image1, struct pgm image2) {
    double mse = 0.0;

    for (int i = 0; i < SUBIMAGEWIDTH; i++) {
        for (int j = 0; j < SUBIMAGEHEIGHT; j++) {
            mse += (image1.pData[i+j*(image1.r)] - image2.pData[i+j*(image1.r)]) * (image1.pData[i+j*(image1.r)] - image2.pData[i+j*(image1.r)]);
        }
    }

    mse /= (SUBIMAGEWIDTH * SUBIMAGEHEIGHT);

    return mse;
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


