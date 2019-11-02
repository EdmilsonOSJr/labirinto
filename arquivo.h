#ifndef ARQUIVO_H_INCLUDED
#define ARQUIVO_H_INCLUDED

typedef struct{
    int linha,coluna,lEntrada,lSaida,cEntrada,cSaida;
}TDados;

typedef TDados*dados;

int verificacaExtensao(char **,char*);
char** coletaDadosDoArquivo(char*,dados*);
FILE * abrirArquivo(char*);
void leLabirintoNoArq(FILE *,char **,dados);
char **alocaMemoriaDaMatriz(dados);
#endif // ARQUIVO_H_INCLUDED
