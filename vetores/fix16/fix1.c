#include <stdio.h>
#include <stdlib.h>

#define TAM 10
int main()
{
	int i;

	// declaramos uma var que irá apontar para o buffer alocado
	int* vetor;

	// chamar funç que irá alocar o espalo 
	vetor = (int*)malloc(TAM * sizeof(int));

	// usamos o espaço do vetor
	for(i=0;i<TAM;i++)
	{
		scanf("%d",&vetor[i]);
	}
	for(i=0;i<TAM;i++)
	{
		printf("vetor[%d]: %d",i, vetor[i]);
	}
	
	// libera o espaço
	free(vetor);
	
	return 0;
}
