#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int buscaVetor(int* vetor, int n, int procurado);

void printaVetor(int vetor[], int n);

int main()
{
	int vetor[N], i, busca, resposta;
	srand(time(NULL));

	for(i=0;i<N;i++)
	{
		vetor[i] = rand()%20;
	}
	
	printaVetor(vetor,N);

	printf("Informe o valor para busca:\n");
	scanf("%d", &busca);

	printf("%d\n", buscaVetor(vetor, N, busca));

	return 0;
}

int buscaVetor(int* vetor, int n, int procurado)
{
	int i, position;

	for(i=0;i<n;i++)
	{
		if(vetor[i]==procurado)
		{
			position = i;
			break;
		}	
		else
			position = -1;
	}
	return position;
}

void printaVetor(int vetor[], int n)
{
	int i;

	for(i=0;i<n;i++)
	{
		printf("vetor[%d]:%d\n",i, vetor[i]);
	}
}
