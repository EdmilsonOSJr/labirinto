#ifndef LABIRINTO_H_INCLUDED
#define LABIRINTO_H_INCLUDED

#include "pilha.h"
#include "lista.h"
#include "arquivo.h"

/*Nessa função é colocada a primeira posição na pilha e depois é iniciado um  loop que apenas será quebrado caso a posição atual
da pilha for igual a essa primeira posição de entrada*/
void andar(char**,dados);


/*Como a saída do labirinto sempre proporciona apenas um caminho para movimentação essa função cuida de descobrir qual seria
esse para assim evitar testes desnecessários*/
int verificaDirecaoDeSaida(dados);


/*Assim que se assume um novo elemento na pilha a posição dele no labirinto, que está na matriz, é marcado com um 'v' que
significa que essa posição foi visitada
*/
void demarcaCaminho(char**,TElemento);


/*Verifica se o caminho correspondente a variável peek é válido. Caso seja anda por ele marcando a matriz com 'v' e inserindo o
elemento na pilha*/
void caminhoPossivel(pilha,char**,dados,lista);


/*Recebe a pilha, dados do labirinto e uma variável TElemento como referencia. A partir da variável peek presente no topo da pilha
, que representa qual caminho deseja-se percorrer, é calculado o próximo elemento que será colocado na pilha. Tendo todos os
dados relativos a essa nova posição guardados na variável e(TElemento). caso seja o primeiro elemento que entrara na pilha
não é necessário fazer calculos pois os dados da posição estarão na variável do tipo dados(linha e coluna de entrada por exemplo).
depois de feiro isso tudo o peek do topo atual da pilha é incrementado para que ao voltar nessa posição possam ser exploradas
novos caminhos*/
void proximaPosicao(TElemento*,pilha,dados);


/*Quando a pilha realiza o pop significa que o caminho realizado e marcado na matriz está sendo  refeito. Portanto essa função
volta o valor 'v' para o valor 0 original
*/
void voltaOCaminhoAoNormal(char **,TElemento);


/*Anda por um elemento na matriz marcando-a e inserindo o elemento na pilha*/
void percorreMatriz(pilha,dados,char**);


/*Verifica se a posição atual corresponde a saída. Em caso verdadeiro é realizado pop na pilha e a posição que foi retirada é
marcada na matriz com '0' ao invés do 'v'*/
int verificaSeAchouFinal(dados,pilha,char**,lista);


/*Verifica se o peek da posição atual quer voltar a posição anterior, entretanto só é permitiddo voltar pelo caminho já
percorrido caso não tenha mais saídas e assim seja necessário usar o pop na pilha*/
int verificaRetornoInvalido(pilha p);


/*Aqui o caminho que chegou no final é escrito na lista. Isso ocorre em dois casos se o tamanho da lista é 0 ou se o tamanho da
pilha for menor que o da fila atual*/
void passaCamiinhoParaLista(pilha,lista);

/*Passa O menor caminho para o arquio de saida junto de uma representação do labirinto com o menir caminho marcado com '1'*/
void passaMelhorCaminhoParaArqDeSaida(dados,lista,char**);

/*Libera a memória alocada para a matriz*/
char **terminaMatriz(dados,char **);

#endif // LABIRINTO_H_INCLUDED
