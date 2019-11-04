#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include "pilha.h"

typedef struct nodofila
{
    struct nodofila *prox;
    TElemento info;
}TNodoFila;

typedef struct
{
    TNodoFila *inicio,*fim;
    int tamanho;
}TFila;

typedef TFila* fila;

fila criaFila();
int enfilera(fila,TElemento);
int desenfilera(fila,TElemento*);
void terminaFila(fila);

#endif // FILA_H_INCLUDED
