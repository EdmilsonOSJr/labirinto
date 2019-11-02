#include <stdio.h>
#include <stdlib.h>
//#include "funcaoAuxiliar.h"
#include "arquivo.h"

int iniciar(int nomes,char**arquivo)
{
    char entrada[100];
    char **matriz;
    dados d;
    int i,j;

    if(verificacaExtensao(arquivo,entrada)==0)
        printf("\nEstensão do arquivo incorreta!!!");
    else
    {
       matriz=coletaDadosDoArquivo(entrada,&d);
    }
    for(i=0;i<d->linha;i++){
        for(j=0;j<d->coluna;j++)
            printf("%c",matriz[i][j]);
        printf("\n");
    }


    printf("\nSaida: %c\n",matriz[d->lSaida][d->cSaida]);
    printf("\nEntrada: %c\n",matriz[d->lEntrada][d->cEntrada]);
    return 0;
}

int main(int argc,char *argv[])
{
    return iniciar(argc,argv);
}
