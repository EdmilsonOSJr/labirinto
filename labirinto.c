#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivo.h"
#include "labirinnto.h"
#include "pilha.h"
#include "lista.h"

void passaCamiinhoParaFila(pilha p,lista l)
{
    pilha p2;
    TElemento e;
    TNodo *paux;

    p2=criaPilha();

    if(p->tamanho<l->sizeLista || l->sizeLista==0)
    {
        while(l->first!=NULL)
        {
           remove_elemento(l,1);
        }

        paux=p->topo;
        while(paux!=NULL)
        {
            e=paux->info;
            push(p2,e);
            paux=paux->prox;
        }

        while(p2->topo!=NULL)
        {
            pop(p2,&e);
            insere_final(l,e);
        }
    }
    terminaPilha(p2);

}

void andaMatriz(dados d,char** matriz){
    int i,j;

    for(i=0;i<d->linha;i++){
        for(j=0;j<d->coluna;j++)
            printf("%c",matriz[i][j]);
        printf("\n");
    }
    printf("\n");
}


void percorreMatriz(pilha p,dados d,char** matriz)
{
    TElemento e;

    proximaPosicao(&e,p,d);
    push(p,e);
    demarcaCaminho(matriz,e);
    andaMatriz(d,matriz);
}


int verificaSeAchouFinal(dados d,pilha p,char**matriz,lista l)
{
    TElemento e;

    if(d->lSaida==p->topo->info.linha && d->cSaida==p->topo->info.coluna)
    {
        passaCamiinhoParaFila(p,l);
        pop(p,&e);
        voltaOCaminhoAoNormal(matriz,e);
        printf("\nAchou\n");

        return 1;
    }
    else
        return  0;
}


int verificaRetornoInvalido(pilha p)
{
    if(p->topo->prox!=NULL && p->topo->info.peekNaoPode==p->topo->info.peek)
    {
        (p->topo->info.peek)=p->topo->info.peek+1;
        return 1;
    }
    return 0;
}


void proximaPosicao(TElemento *e,pilha p,dados d)
{
    if(p->tamanho==0)
    {
        e->linha=d->lEntrada;
        e->coluna=d->cEntrada;
        e->peek=verificaDirecaoDeSaida(d);
    }
    else
    {
        switch(p->topo->info.peek)
        {
            case 1:
                e->linha=p->topo->info.linha;
                e->coluna=(p->topo->info.coluna)+1;
                e->peek=1;
                e->peekNaoPode=3;
            break;
            case 2:
                e->linha=(p->topo->info.linha)+1;
                e->coluna=p->topo->info.coluna;
                e->peek=1;
                e->peekNaoPode=4;
            break;
            case 3:
                e->linha=p->topo->info.linha;
                e->coluna=(p->topo->info.coluna)-1;
                e->peek=1;
                e->peekNaoPode=1;
            break;
            case 4:
                e->linha=(p->topo->info.linha)-1;
                e->coluna=p->topo->info.coluna;
                e->peek=1;
                e->peekNaoPode=2;
            break;

            default:
            break;

        }
        (p->topo->info.peek)=p->topo->info.peek+1;
    }

}


void demarcaCaminho(char **matriz,TElemento e)
{
    matriz[e.linha][e.coluna]='v';
}


void voltaOCaminhoAoNormal(char **matriz,TElemento e)
{
    matriz[e.linha][e.coluna]='0';
}


int verificaDirecaoDeSaida(dados d)
{

    if(d->lEntrada==0)
        return 2;
    else
        if(d->lEntrada==d->linha-1)
            return 4;
        else
            if(d->cEntrada==0)
                return 1;
            else
                if(d->cEntrada==d->coluna-1)
                    return 3;
    return 0;
}


void caminhoPossivel(pilha p,char**matriz,dados d,lista l)
{
    TElemento e;

    do
    {
        if(p->tamanho<l->sizeLista || l->sizeLista==0)
        {


            switch(p->topo->info.peek)
            {
                case 1:

                    if(verificaSeAchouFinal(d,p,matriz,l)==0)
                    {
                        if(verificaRetornoInvalido(p)==0)
                        {
                            if(matriz[p->topo->info.linha][(p->topo->info.coluna)+1]=='0')
                            {
                                percorreMatriz(p,d,matriz);
                            }
                            else
                                (p->topo->info.peek)=p->topo->info.peek+1;
                        }
                    }

                break;

                case 2:

                    if(verificaSeAchouFinal(d,p,matriz,l)==0)
                    {
                        if(verificaRetornoInvalido(p)==0)
                        {
                            if(matriz[(p->topo->info.linha)+1][p->topo->info.coluna]=='0')
                            {
                                percorreMatriz(p,d,matriz);
                            }
                             else
                                (p->topo->info.peek)=p->topo->info.peek+1;
                        }
                    }

                break;

                case 3:

                    if(verificaSeAchouFinal(d,p,matriz,l)==0)
                    {
                        if(verificaRetornoInvalido(p)==0)
                        {
                            if(matriz[p->topo->info.linha][(p->topo->info.coluna)-1]=='0')
                            {
                                percorreMatriz(p,d,matriz);
                            }
                             else
                                (p->topo->info.peek)=p->topo->info.peek+1;
                        }
                    }

                break;

                case 4:

                    if(verificaSeAchouFinal(d,p,matriz,l)==0)
                    {
                        if(verificaRetornoInvalido(p)==0)
                        {
                            if(matriz[(p->topo->info.linha)-1][p->topo->info.coluna]=='0')
                            {
                                percorreMatriz(p,d,matriz);
                            }
                             else
                                (p->topo->info.peek)=p->topo->info.peek+1;
                        }
                    }

                break;

            }
        }
        else
        {
            pop(p,&e);
            voltaOCaminhoAoNormal(matriz,e);

            printf("\nMAIOR QUE F\n");
            andaMatriz(d,matriz);
        }
    }while((p->topo->info.peek)<5 );

    pop(p,&e);
    voltaOCaminhoAoNormal(matriz,e);

    printf("\nsem saida\n");
    andaMatriz(d,matriz);
}

void printaMelhorCaminho(dados d,lista l,char**matriz)
{
   TNodoLista *n;

    n=l->first;
    while(n!=NULL)
    {
        matriz[n->info.linha][n->info.coluna]='1';
        n=n->next;
    }

    printf("\n===================MENOR CAMINHO===================\n");
    printf("\n");

    n=l->first;
    while(n!=NULL)
    {
        printf(" Matriz[%d][%d] ",n->info.linha,n->info.coluna);
        n=n->next;
    }
    printf("\n");
    printf("\n");

    andaMatriz(d,matriz);
}


void andar(char** matriz,dados d)
{
    pilha p;
    lista l;
    TElemento e;

    l=cria_lista();
    p=criaPilha();
    proximaPosicao(&e,p,d);
    push(p,e);
    demarcaCaminho(matriz,p->topo->info);

    do
    {
        caminhoPossivel(p,matriz,d,l);

    }while(d->lEntrada!=p->topo->info.linha || d->cEntrada!=p->topo->info.coluna);

    printaMelhorCaminho(d,l,matriz);

    printf("\nFIM\n");
    terminaPilha(p);
    termina_lista(l);
}
