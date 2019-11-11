#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

lista cria_lista(){

    lista l;

    l = (lista)malloc(sizeof(TLista));

    if(l){ //(lista!=NULL)
        l->first = NULL;
        l->last = NULL;
        l->sizeLista=0;
    }

    return l;

}//cria_lista;

void termina_lista(lista l){

    TNodoLista *p;

    while(l->first != NULL){
        p = l->first;
        l->first = l->first->next;
        free(p);
    }

    free(l);

}//termina_lista

int insere_final(lista l, TElemento e){

    TNodoLista *p;

    p = (TNodoLista*)malloc(sizeof(TNodoLista));

    if(p==NULL)
        return 0;

    p->info=e;
    p->next = NULL;

    if(l->first==NULL)
        l->first = p;

    else
        l->last->next = p;

    l->last = p;
    l->sizeLista++;

    return 1;
}

int remove_elemento(lista l, int indice){
    TNodoLista *p, *ant;
    int i;

    if(indice>=1 && indice<=l->sizeLista){
        p=l->first;

        for(i=1; i<indice; i++){

            ant = p;
            p=p->next;
        }

    if(l->first==p)

        l->first = l->first->next; /*l->first = p->next*/

        else if(l->last==p){
            l->last = ant;
            l->last->next = NULL;
        }

        else
            ant->next = p->next;

        free(p);
        l->sizeLista--;
        return 1;

    }

    return 0;
}
