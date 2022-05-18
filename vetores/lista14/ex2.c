#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int main()
{
	int vetor[N];
	int i;
	int nValores = N;
	int pos;

	// gera e mostra vetor
	for(i=0 ; i<N ; i++)
	{
		vetor[i] = rand();
		printf("%4d %d\n", i, vetor[i]);
	}	

	// loop lendo e removendo valores do vetor
	printf("Informe o qual será removido:\n");
	scanf("%d", &pos);
	while(nValores > 0 && pos >= 0 && pos < nValores)
	{
		// desloca todos os valores a partir da posição dada para a esquerda
		for(i = pos+1 ; i<nValores ; i++)
		{
			vetor[i-1] = vetor[i];
		}
		nValores--;
				// mostra o vetor
		for(i = 0 ; i < nValores ; i++)
		{
			printf("%4d %d\n", i, vetor[i]);
		}
		
		// se o vator ainda tem slot
		if(nValores > 0)
		{	
			printf("Informe o qual será removido:\n");
			scanf("%d", &pos);
		}					
	}
	return 0;
	
}
