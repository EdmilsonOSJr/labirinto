#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivo.h"
#include "labirinnto.h"
#include "pilha.h"


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


void possiveisCaminhos(pilha p,char**matriz,dados d)
{
    TElemento e;
    int i,j;

    do
    {
        switch(p->topo->info.peek)
        {
            case 1:
                if(d->lSaida==p->topo->info.linha && d->cSaida==p->topo->info.coluna)
                {
                    pop(p,&e);
                    voltaOCaminhoAoNormal(matriz,e);
                }
                else
                {

                    if(p->topo->prox!=NULL && p->topo->info.peekNaoPode==p->topo->info.peek)
                        (p->topo->info.peek)=p->topo->info.peek+1;
                    else
                    {
                        if(matriz[p->topo->info.linha][(p->topo->info.coluna)+1]=='0')
                        {
                            proximaPosicao(&e,p,d);
                            push(p,e);
                            demarcaCaminho(matriz,e);
                            for(i=0;i<d->linha;i++){
                                for(j=0;j<d->coluna;j++)
                                    printf("%c",matriz[i][j]);
                                printf("\n");
                            }
                            printf("\n");
                        }
                        else
                            (p->topo->info.peek)=p->topo->info.peek+1;
                    }
                }
            break;
            case 2:
                if(d->lSaida==p->topo->info.linha && d->cSaida==p->topo->info.coluna)
                {
                    pop(p,&e);
                    voltaOCaminhoAoNormal(matriz,e);
                }
                else
                {
                    if(p->topo->prox!=NULL && p->topo->info.peekNaoPode==p->topo->info.peek)
                        (p->topo->info.peek)=p->topo->info.peek+1;
                    else
                    {
                        if(matriz[(p->topo->info.linha)+1][p->topo->info.coluna]=='0')
                        {
                            proximaPosicao(&e,p,d);
                            push(p,e);
                            demarcaCaminho(matriz,e);
                            for(i=0;i<d->linha;i++){
                                for(j=0;j<d->coluna;j++)
                                    printf("%c",matriz[i][j]);
                                printf("\n");
                            }
                            printf("\n");
                        }
                         else
                            (p->topo->info.peek)=p->topo->info.peek+1;
                    }
                }
            break;
            case 3:
                if(d->lSaida==p->topo->info.linha && d->cSaida==p->topo->info.coluna)
                {
                    pop(p,&e);
                    voltaOCaminhoAoNormal(matriz,e);
                }
                else
                {
                    if(p->topo->prox!=NULL && p->topo->info.peekNaoPode==p->topo->info.peek)
                        (p->topo->info.peek)=p->topo->info.peek+1;
                    else
                    {
                        if(matriz[p->topo->info.linha][(p->topo->info.coluna)-1]=='0')
                        {
                            proximaPosicao(&e,p,d);
                            push(p,e);
                            demarcaCaminho(matriz,e);
                            for(i=0;i<d->linha;i++){
                                for(j=0;j<d->coluna;j++)
                                    printf("%c",matriz[i][j]);
                                printf("\n");
                            }
                            printf("\n");
                        }
                         else
                            (p->topo->info.peek)=p->topo->info.peek+1;
                    }
                }
            break;
            case 4:
                if(d->lSaida==p->topo->info.linha && d->cSaida==p->topo->info.coluna)
                {
                    pop(p,&e);
                    voltaOCaminhoAoNormal(matriz,e);
                }
                else
                {
                    if(p->topo->prox!=NULL && p->topo->info.peekNaoPode==p->topo->info.peek)
                        (p->topo->info.peek)=p->topo->info.peek+1;
                    else
                    {
                        if(matriz[(p->topo->info.linha)-1][p->topo->info.coluna]=='0')
                        {
                            proximaPosicao(&e,p,d);
                            push(p,e);
                            demarcaCaminho(matriz,e);
                            for(i=0;i<d->linha;i++){
                                for(j=0;j<d->coluna;j++)
                                    printf("%c",matriz[i][j]);
                                printf("\n");
                            }
                            printf("\n");
                        }
                         else
                            (p->topo->info.peek)=p->topo->info.peek+1;
                    }
                }
            break;
        }
    }while((p->topo->info.peek)<5);
    pop(p,&e);
    voltaOCaminhoAoNormal(matriz,e);
    printf("\nsem saida\n");
    for(i=0;i<d->linha;i++){
        for(j=0;j<d->coluna;j++)
            printf("%c",matriz[i][j]);
        printf("\n");
    }
}


void robo(char** matriz,dados d)
{
    ///int i,j;
    pilha p;
    TElemento e;

    p=criaPilha();
    proximaPosicao(&e,p,d);
    push(p,e);
    demarcaCaminho(matriz,p->topo->info);

    do
    {
        possiveisCaminhos(p,matriz,d);
        printf("\nLinha: %d",p->topo->info.linha);
        printf("\nColuna: %d",p->topo->info.coluna);
        printf("\nLinha de saida: %d",d->lEntrada);
        printf("\nColuna de saida: %d",d->cEntrada);

    }while(d->lEntrada!=p->topo->info.linha || d->cEntrada!=p->topo->info.coluna);

    printf("\nFIM\n");

    /*for(i=0;i<d->linha;i++){
        for(j=0;j<d->coluna;j++)
            printf("%c",matriz[i][j]);
        printf("\n");
    }
    */



}
