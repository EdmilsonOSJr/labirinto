#include <stdio.h>
#include <stdlib.h>
#include "labirinnto.h"
#include "arquivo.h"

int iniciar(int nomes,char**arquivo)
{
    char entrada[100];
    char **matriz;
    dados d;

    if(verificacaExtensao(arquivo,entrada)==0)
        printf("\nEstensão do arquivo incorreta!!!");
    else
    {
       matriz=coletaDadosDoArquivo(entrada,&d);
       andar(matriz,d);
    }

    return 0;
}

int main(int argc,char *argv[])
{
    return iniciar(argc,argv);
}
