#ifndef ARQUIVO_H_INCLUDED
#define ARQUIVO_H_INCLUDED

/*Estrutura utilizada para pegar os dados do labirinto correspondentes as duas primeiras linhas do arquivo*/
typedef struct{
    int linha,coluna,lEntrada,lSaida,cEntrada,cSaida;
}TDados;

typedef TDados*dados;


/*Verifica se o arquivo tem a extensão  correta*/
int verificacaExtensao(char **,char*);


/*São coletados od dados do arquivo onde as suas duas primeiras linhas ficam numa variável o tio dados e o labirinto fica em uma
matriz alocada dinamicamente*/
char** coletaDadosDoArquivo(char*,dados*);


/*Abre o arquivo e retorna um ponteiro, que está apontando para o arquivo aberto*/
FILE * abrirArquivo(char*);


/*Os elementos do labirinto são colocados dentro da matriz*/
void passaLabirintoParaMatriz(FILE *,char **,dados);


/*A matriz é alocada dinamicamente e retornada*/
char **alocaMemoriaDaMatriz(dados);

#endif // ARQUIVO_H_INCLUDED
