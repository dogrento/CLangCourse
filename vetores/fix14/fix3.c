#include <stdio.h>

#define N 5

int eh_crescente(int* vetor, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(vetor[i]>vetor[i+1])
			return 0;
	}
	return 1;
}

int main()
{
	int i;
	int vetor[N];

	for (i=0;i<N;i++)
	{
		scanf("%d", &vetor[i]);
	}

	printf("%d\n", eh_crescente(vetor, N));

	return 0;
}
