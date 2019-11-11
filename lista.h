#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "pilha.h"

typedef struct nodolista
{
    struct nodolista *next;
    TElemento info;
}TNodoLista;

typedef struct
{
    TNodoLista *first,*last;
    int sizeLista;
}TLista;

typedef TLista* lista;

lista cria_lista();
void termina_lista(lista);
int insere_final(lista,TElemento);
int remove_elemento(lista,int);

#endif // LISTA_H_INCLUDED
