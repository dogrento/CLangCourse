// importar libs
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// macro definindo o limite de posições do vetor
#define LMT 10

int main()
{
	// declarando vars do tipo inteiro 
	int i,
	    count = 0,
	    vetor[LMT];// vetor com conteudo rand

	// função rand baseado no time
	srand(time(NULL));

	// atribuindo valor a cada posição do vetor com loop
	for(i=0 ; i<LMT ; i++)
	{
		// posição do vetor recebe o resto da div de rand por LMT
		vetor[i] = rand() % LMT;
		printf("v[%d]: %d ", i, vetor[i]);
	}
	// pular linha
	printf("\n");
	// se para cada  posição do vetor for igual ao conteudo dele
	for(i=0 ; i<LMT ; i++)
	{
		if(vetor[i]==i)
		{
			printf("v[%d]:%d\n", vetor[i], i);
			count++;
		}
	}
	if(count>1)
		printf("Há %d que combinaram.\n", count);
	else
		printf("Há apenas um que combinou\n");
	
	return 0;
}
