#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef int TChave;

typedef struct{
    int peek;
    int linha;
    int coluna;
}TElemento;

typedef struct nodo {
    TElemento info;
    struct nodo *prox;
}TNodo;

typedef struct {
    TNodo *topo;
    int tamanho;
}TPilha;

typedef TPilha * pilha;

pilha criaPilha();
int push(pilha,TElemento);
int pop(pilha,TElemento*);
void terminaPilha(pilha);

#endif // PILHA_H_INCLUDED
