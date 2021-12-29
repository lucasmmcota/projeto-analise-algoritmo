#include <stdio.h>
#include <stdlib.h>

#include "programacao_dinamica.h"
#include "operacoes.h"

/*	Entrada:
		distancia[] -> Vetor de distancia entre os planetas
		n -> Numero de planetas
		k -> Numero de planetas a serem conquistados
		atual -> Planeta atual (comeca do fim, ou seja, n + 1)
	Saida:
		Maior sub distancia entre os planetas da solucao otima */
int programacao_dinamica(int distancia[], int n, int k, int atual)
{
	if (k == 0) // Distancia do inicio ao ultimo planeta (atual)
	{
		return custo_sub_distancia(distancia, 0, atual);
	}
	else if (n == 0) // Nao tem mais planetas para passar
	{
		return 0;
	}
	else if (k == n) // Conquistar proximo planeta
	{
		return maior(custo_sub_distancia(distancia, n, atual),
					 programacao_dinamica(distancia, n - 1, k - 1, n));
	}
	else // Verifica se deve ir para o proximo planeta ou pular ele
	{
		int proximoPlaneta =
			maior(custo_sub_distancia(distancia, n, atual),
				  programacao_dinamica(distancia, n - 1, k - 1, n));

		int pularProximoPlaneta =
			maior(custo_sub_distancia(distancia, n - 1, atual),
				  programacao_dinamica(distancia, n - 1, k, atual));

		return menor(proximoPlaneta, pularProximoPlaneta);
	}
}