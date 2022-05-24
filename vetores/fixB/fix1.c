#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// macro
# define N 10

// função que verifica se um int pertence ao vetor
int buscaVetor(int *vetor, int n, int procurado)
{
	int i;
        

	for(i=0 ; i<n ; i++)
	{
		if(vetor[i] == procurado)
		{
			printf("posição do vetor[%d]", i);
		}
	}
}

int main()
{
	int vetor[N], i, procurado;

	// função rand baseado em time
	srand(time(NULL));

	for(i=0 ; i<N ; i++)
	{
		vetor[i] = rand() % N;
	}

	printf("Informe um valor a ser procurado:\n");
	scanf("%d", &procurado);

	buscaVetor(vetor, N, procurado);

	return 0;
}
