#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int comuns = 360;
    int incomuns = 108;
    int raras = 32;
    int miticas = 4;

    int qtdMit, qtdRar, qtdInc, qtdCom;
    float totMit, totRar, totInc, totCom;
    float precoBox;

    float medMit, medRar, medInc, medCom;

    float evFinal;
    float perda;

    printf("Insira o preço de compra da caixa: "); scanf(" %f",&precoBox);

    printf("Insira o numero total de miticas : "); scanf(" %i",&qtdMit);
    printf("Insira o numero total de raras : "); scanf(" %i",&qtdRar);
    printf("Insira o numero total de incomuns : "); scanf(" %i",&qtdInc);
    printf("Insira o numero total de comuns : "); scanf(" %i",&qtdCom);

    printf("insira o preço total das miticas : "); scanf(" %f",&totMit);
    printf("insira o preço total das raras : "); scanf(" %f",&totRar);
    printf("insira o preço total das incomuns : "); scanf(" %f",&totInc);
    printf("insira o preço total das comuns : "); scanf(" %f",&totCom);

    medMit = totMit/qtdMit;
    medRar = totRar/qtdRar;
    medInc = totInc/qtdInc;
    medCom = totCom/qtdCom;

    evFinal = medMit*(miticas) + medRar*(raras) + medInc*(incomuns) + medCom*(comuns);
    perda = 100*(1-evFinal/precoBox);

    printf("Em media cada comum custa : %.2f\n",medCom);
    printf("Em media cada incomum custa : %.2f\n",medInc);
    printf("Em media cada rara custa : %.2f\n",medRar);
    printf("Em media cada mitica custa : %.2f\n",medMit);
    printf("Em média você angariará %.2f R$ da caixa\n",evFinal);
    printf("Isso representa uma perda de %.2f%%\n",perda);
    return 0;
}