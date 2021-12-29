#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "operacoes.h"
#include "operacoes.c"

#include "algoritmo_guloso.h"
#include "algoritmo_guloso.c"

#include "forca_bruta.h"
#include "forca_bruta.c"

#include "programacao_dinamica.h"
#include "programacao_dinamica.c"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Parametros invalidos !\n");
        printf("Encerrando o programa...\n");
        return 0;
    }

    int i, t, n, k, *distancia;

    scanf("%d", &t);

    // verificar t, n e k
    // if (t < 0 || t > 100)
    // {
    //     printf("Numero de instancias invalido !\n");
    //     printf("Encerrando o programa...\n");
    //     return 0;
    // }

    for (i = 0; i < t; i++)
    {
        scanf("%d %d", &n, &k);
        // while (n < 1 || n > 500 || k < 0 || k > 250 || k > n)
        // {
        //     printf("Numero de n e k invalido na instancia %d!\n", i + 1);
        //     distancia = (int *)calloc(n + 1, sizeof(int));
        //     le_distancias(distancia, n);
        //     scanf("%d %d", &n, &k);
        // }

        distancia = (int *)calloc(n + 1, sizeof(int));
        ler_sub_distancias(distancia, n);

        switch (escolher_algoritmo(argv))
        {
        case 1:
            printf("%d\n", algoritmo_guloso(distancia, n, k));
            break;

        case 2:
            printf("%d\n", forca_bruta(distancia, n, k));
            break;

        case 3:
            printf("%d\n", programacao_dinamica(distancia, n, k, n + 1));
            break;

        default:
            printf("\nAlgoritmo de solucao invalido!\n");
            printf("Encerrando o programa...\n");
            return 0;
        }

        free(distancia);
    }

    return 0;
}