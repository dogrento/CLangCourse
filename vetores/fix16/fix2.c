#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i, tam1,tam2;
	srand(time(NULL));
	// declarar dois ponteiros para buffer alocado
	int* vetor1, *vetor2;

	// definir tam1 e tam2
	printf("Informe o tam1 e tam2");
	scanf("%d %d", &tam1, &tam2);

	// funç que irá alocar o espaço 
	vetor1 = (int*) malloc(tam1 * sizeof(int));
	vetor2 = (int*) malloc(tam2 * sizeof(int));	

	// usar espaços alocados
	for(i=0;i<tam1;i++)
	{
		vetor1[i] = rand()%10;
		printf("vetor1[%d]:%d\n",i, vetor1[i]);
	}
	for(i=0;i<tam2;i++)
	{
		vetor2[i] = rand()%10;
		printf("vetor2[%d]:%d\n",i, vetor2[i]);
	}

	// liberar espaços
	free(vetor1);
	free(vetor2);

	return 0;
}
