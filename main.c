#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "labirinto.h"
#include "arquivo.h"

int iniciar(int nomes,char**arquivo)
{
    char entrada[100];
    char **matriz;
    dados d;
    setlocale(LC_ALL,"pt-BR");

    if(verificacaExtensao(arquivo,entrada)==0)
        printf("\nEstensão do arquivo incorreta!!!");
    else
    {
       matriz=coletaDadosDoArquivo(entrada,&d);
       if(matriz!=NULL)
            andar(matriz,d);
    }

    return 0;
}

int main(int argc,char *argv[])
{
    return iniciar(argc,argv);
}
