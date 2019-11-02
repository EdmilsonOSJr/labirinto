#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

pilha criaPilha()
{
    pilha p;

    p=(pilha)malloc(sizeof(TPilha));

    if(p)
    {
        p->topo=NULL;
        p->tamanho=0;
    }
    return p;
}

int push(pilha p,TElemento e)
{
    TNodo *n;

    n=(TNodo*)malloc(sizeof(TNodo));

    if(n==NULL)
        return 0;

    n->info=e;
    n->prox=p->topo;
    p->topo=n;
    p->tamanho++;
    return 1;
}

int pop(pilha p,TElemento *e)
{
    TNodo *n;

    if(p->tamanho==0)
        return 0;

    *e=p->topo->info;
    n=p->topo;
    p->topo=n->prox;
    p->tamanho--;
    free(n);
    return 1;
}

void terminaPilha(pilha p)
{
    TNodo *n;

    if(p->tamanho!=0)
    {
        while(p->topo!=NULL)
        {
            n=p->topo;
            p->topo=n->prox;
            free(n);
        }
    }
    free(p);
}
