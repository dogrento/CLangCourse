#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// macro para definir o tamanho do vetor
#define N 100

int main()
{
	int media, soma, i, vetor[N];

	//função rand baseado no time
	srand(time(NULL));


	// atribuindo N valores aleatórios ao vetor
	for(i=0 ; i<N ; i++)
	{
		vetor[i] = rand()%60 + 20;

		printf("vetor[%d]:%d\n",i ,vetor[i]);
	}

	// somando todos os valores do vetor
	for(i=0 ; i<N ; i++)
	{
		soma+=vetor[i];
	}

	//caldulando média e imprimindo
	printf("soma: %d\n", soma);
	printf("media:%.2f", (float)soma/N);

	return 0;
}
