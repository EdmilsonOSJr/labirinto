#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivo.h"

FILE* abrirArquivo(char *arqEntrada)
{
    FILE *arq;

    arq = fopen(arqEntrada, "r+");
    return arq;
}

int verificacaExtensao(char ** comando,char *entrada)
{
    if(strstr(comando[1],".txt")!=NULL)
    {
        strcpy(entrada,comando[1]);
        return 1;
    }
    else
        return 0;
}

void leLabirintoNoArq(FILE *arq,char **m,dados d)
{
    char elementoDoLabirinto;
    int l=0,c=0;

    do
    {
        elementoDoLabirinto=getc(arq);
        if(elementoDoLabirinto!='\n')
        {
            m[l][c]=elementoDoLabirinto;
            c++;
            if(c>=d->coluna)
            {
                l++;
                c=0;
            }
        }
    }while(elementoDoLabirinto!=EOF);
}

char **alocaMemoriaDaMatriz(dados d)
{
    char **m;
    int i;

    m=(char**)malloc(sizeof(char*)*d->linha);
    for(i=0;i<d->coluna;i++)
        m[i]=(char*)malloc(sizeof(char)*d->linha);
    return m;
}

char** coletaDadosDoArquivo(char*entrada,dados *d)
{
    char **matriz;
    FILE *arqEntrada;
    int l,c,lE,cE,lS,cS;

    arqEntrada=abrirArquivo(entrada);

    if(arqEntrada==NULL)
        printf("\nArquivo não encontrado!!!");
    else
    {
        *d=(dados)malloc(sizeof(TDados));

        fscanf(arqEntrada,"%d%d",&l,&c);
        (*d)->linha=l;
        (*d)->coluna=c;

        fscanf(arqEntrada,"%d%d%d%d",&cE,&lE,&cS,&lS);
        (*d)->lEntrada=lE;
        (*d)->cEntrada=cE;
        (*d)->lSaida=lS;
        (*d)->cSaida=cS;

        matriz=alocaMemoriaDaMatriz(*d);
        leLabirintoNoArq(arqEntrada,matriz,*d);

    }
    return matriz;
}
