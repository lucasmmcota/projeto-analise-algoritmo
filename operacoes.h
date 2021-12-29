#ifndef OPERACOES_H_INCLUDED
#define OPERACOES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/* Retorna o codigo do algoritmo a ser utilizada para solucao do problema. */
int escolher_algoritmo(char *argv[]);

/* Le e registra em '*distancia' as sub distancias entre os planetas. */
void ler_sub_distancias(int *distancia, int n);

/* Retorna o custo em percorrer a distancia de 'inicio' ao 'fim'. */
int custo_sub_distancia(int distancia[], int inicio, int fim);

/* Retorna o maior numero entre 'a' e 'b'. */
int maior(int a, int b);

/* Retorna o menor numero entre 'a' e 'b'. */
int menor(int a, int b);

#endif