#include <stdio.h>

#define N 3
int main()
{
	int j, i, vetor[N];
	
	// lendo valores do teclado e armazenando no vetor
	for(i=0 ; i<N ; i++)
	{
		scanf("%d", &vetor[i]);
	}

	for(j=N-1 ; j>=0 ; j--)
	{
		printf("vetor[%d]:%d\n", j, vetor[j]);
	}
	return 0;
}
