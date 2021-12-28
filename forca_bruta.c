#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "forca_bruta.h"
#include "operacoes.h"

/*  Entrada:
        distancia[] -> Vetor de sub distancias
        n -> Numero de planetas
        k -> Numero de planetas a serem conquistados
    Saida:
        sd_global -> Maior sub distancia da solucao otima */
int forca_bruta(int distancia[], int n, int k)
{
    int *sub_distancia;
    sub_distancia = (int *)calloc((n + 1), sizeof(int));
    sub_distancia[0] = 0;

    int atual = 0, sd_global = INT_MAX;

    /*  O algoritmo de forca bruta ira percorrer todas as
        combinacoes possiveis para conquistar 'k' planetas
        em 'n' possiveis. Armazenando em 'sd_global' a maior
        sub distancia da melhor solucao (solucao com as menores
        sub distancias). */
    do
    {
        if (sub_distancia[atual] < n)
        {
            sub_distancia[atual + 1] = sub_distancia[atual] + 1;
            atual += 1;
        }
        else
        {
            sub_distancia[atual - 1] += 1;
            atual -= 1;
        }

        if (atual == k)
        {
            int j = 0, sd_local = 0, aux[atual + 1];

            for (j = 0; j < atual + 1; j++)
            {
                if (j != atual)
                {
                    aux[j] = custo_sub_distancia(distancia, sub_distancia[j], sub_distancia[j + 1]);
                }
                else
                {
                    aux[j] = custo_sub_distancia(distancia, sub_distancia[j], n + 1);
                }

                if (aux[j] > sd_local)
                {
                    sd_local = aux[j];
                }
            }
            if (sd_global > sd_local)
            {
                sd_global = sd_local;
            }
        }
    } while (atual != 0);

    free(sub_distancia);

    return sd_global;
}