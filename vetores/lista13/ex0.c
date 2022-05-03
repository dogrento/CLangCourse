#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

int main()
{
	int media, soma, i, vetor[N];

	//função rand baseado no time
	srand(time(NULL));


	// gerar N valores aleatórios
	for(i=0 ; i<N ; i++)
	{
		vetor[i] = rand()%60 + 20;

		printf("vetor[%d]:%d\n",i ,vetor[i]);
	}

	// calcular e imprimir a média
	for(i=0 ; i<N ; i++)
	{
		soma+=vetor[i];
	}
	printf("soma: %d\n", soma);
	printf("media:%.2f", (float)soma/N);

	return 0;
}
