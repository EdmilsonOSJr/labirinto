#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

fila criaFila()
{
    fila f;

    f=(fila)malloc(sizeof(TFila));

    if(f!=NULL)
    {
        f->fim=NULL;
        f->inicio=NULL;
        f->tamanho=0;
    }
    return f;
}


int enfilera(fila f,TElemento e)
{
    TNodoFila *n;

    n=(TNodoFila*)malloc(sizeof(TNodoFila));

    if(n==NULL)
        return 0;
    else
    {
        n->info=e;
        n->prox=NULL;

        if(f->inicio==NULL)
            f->inicio=n;
        else
            f->fim->prox=n;

        f->fim=n;
        f->tamanho++;
        return 1;
    }
}


int desenfilera(fila f,TElemento*e)
{
    TNodoFila *n;

    if(f->inicio==NULL)
        return 0;
    else
    {
        n=f->inicio;
        f->inicio=f->inicio->prox;
        *e=n->info;
        f->tamanho--;
        free(n);
        return 1;
    }
}


void terminaFila(fila f)
{
    TNodoFila *aux;

    while(f->inicio!=NULL)
    {
        aux=f->inicio;
        f->inicio=f->inicio->prox;
        free(aux);
    }
}
