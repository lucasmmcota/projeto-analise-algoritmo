#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "operacoes.h"

/*  Entrada:
        *argv[] -> Argumentos de entrada pela linha de comando
    Saida:
        1 -> Solucao do problema pelo paradigma do algoritmo guloso
        2 -> Solucao do problema pelo paradigma da forca bruta
        3 -> Solucao do problema pelo paradigma da programacao dinamica */
int escolher_algoritmo(char *argv[])
{
    if (strcmp(argv[1], "AG") == 0)
    {
        return 1;
    }
    else if (strcmp(argv[1], "FB") == 0)
    {
        return 2;
    }
    else if (strcmp(argv[1], "PD") == 0)
    {
        return 3;
    }
    else
    {
        return 0;
    }
}

/*  Entrada:
        *distancia -> Vetor de sub distancias entre os planetas
        n -> Numero de planetas
    Saida:
        Nenhuma */
void ler_sub_distancias(int *distancia, int n)
{
    int i;
    for (i = 0; i <= n; i++)
    {
        scanf("%d", &distancia[i]);
    }
}

/*  Entrada:
        distancia[] -> Vetor de sub distancias
        inicio -> Inicio da sub distancia
        fim -> Final da sub distancia
    Saida:
        custo -> Custo em percorrer a distancia de 'inicio' ao 'fim' */
int custo_sub_distancia(int distancia[], int inicio, int fim)
{
    int i = 0, custo = 0;
    for (i = inicio; i < fim; i++)
    {
        custo += distancia[i];
    }
    return custo;
}

/*  Entrada:
        a -> Numero 'a'
        b -> Numero 'b'
    Saida:
        Maior numero entre 'a' e 'b' */
int maior(int a, int b)
{

    if (a > b)
    {
        return a;
    }
    return b;
}

/*  Entrada:
        a -> Numero 'a'
        b -> Numero 'b'
    Saida:
        Menor numero entre 'a' e 'b' */
int menor(int a, int b)
{
    if (a > b)
    {
        return b;
    }
    return a;
}