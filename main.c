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
       robo(matriz,d);
    }

    return 0;
}

int main(int argc,char *argv[])
{
    return iniciar(argc,argv);
}
