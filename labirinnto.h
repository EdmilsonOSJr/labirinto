#ifndef LABIRINNTO__H_INCLUDED
#define LABIRINNTO__H_INCLUDED

#include "pilha.h"

void robo(char**,dados);
int verificaDirecaoDeSaida(dados);
void demarcaCaminho(char**,TElemento);
void caminhoPossivel(char**,TElemento);
void proximaPosicao(TElemento*,pilha,dados);
void voltaOCaminhoAoNormal(char **,TElemento);
#endif // LABIRINNTO__H_INCLUDED
