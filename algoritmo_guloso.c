#include <stdio.h>
#include <stdlib.h>

#include "algoritmo_guloso.h"

/*  Entrada:
        distancia[] -> Vetor de sub distancias
        n -> Numero de planetas
        k -> Numero de planetas a serem conquistados
    Saida:
        sd_max -> Maior sub distancia da solucao encontrada */
int algoritmo_guloso(int distancia[], int n, int k)
{
    int i, sd_max = 0, sd_atual = 0;
    int *peso_planeta, *distancia_percorrida;

    distancia_percorrida = (int *)calloc(n + 1, sizeof(int));
    peso_planeta = (int *)calloc(n, sizeof(int));

    for (i = 0; i < n; i++)
    {
        peso_planeta[i] = distancia[i] + distancia[i + 1];
        distancia_percorrida[i] = 0;
    }

    distancia_percorrida[n] = 1;

    /*  Escolha gulosa: Passar pelos 'k' planetas de maior peso.
        O peso do planeta e a soma da sub distancia anterior ao planeta
        atual com a sub distancia do planeta atual ao proximo ponto. */
    for (i = 0; i < k; i++)
    {
        int j = 0, maior = -1, indice = -1;

        for (j = 0; j <= n; j++)
        {
            if (peso_planeta[j] > maior && distancia_percorrida[j] != 1)
            {
                maior = peso_planeta[j];
                indice = j;
            }
        }
        distancia_percorrida[indice] = 1;
    }

    /* Calcula a maior sub distancia da solucao encontrada. */
    for (i = 0; i <= n; i++)
    {
        if (distancia_percorrida[i])
        {
            sd_atual += distancia[i];

            if (sd_atual > sd_max)
            {
                sd_max = sd_atual;
            }

            sd_atual = 0;
        }
        else
        {
            sd_atual += distancia[i];
        }
    }

    free(peso_planeta);
    free(distancia_percorrida);

    return sd_max;
}