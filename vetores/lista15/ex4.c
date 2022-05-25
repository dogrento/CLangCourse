#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int main()
{
	int i,
	    inicio,
	    fim;
	int vetor[N];

	srand(time(NULL));

	for(i=0;i<N;i++)
	{
		vetor[i] = rand()%20;
		printf("vetor[%d]: %d\n", i, vetor[i]);
	}
}
