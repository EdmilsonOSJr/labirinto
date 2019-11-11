#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef int TChave;

/*Essa estrutura guarda um peek que seria qual caminho o nodo atual quer percorrer, onde 1=direita, 2=baixo, 3=esquerda e 4=cima.
Ela também guarda a linha e coluna atuais. E a variável peekNaoPode guarda qual é a movimentação que resultaria num retorno
para posição que acabou de ser visitada*/
typedef struct
{
    int peek;
    int peekNaoPode;
    int linha;
    int coluna;
}TElemento;

typedef struct nodo
{
    TElemento info;
    struct nodo *prox;
}TNodo;

typedef struct
{
    TNodo *topo;
    int tamanho;
}TPilha;

typedef TPilha * pilha;

pilha criaPilha();
int push(pilha,TElemento);
int pop(pilha,TElemento*);
void terminaPilha(pilha);

#endif // PILHA_H_INCLUDED
