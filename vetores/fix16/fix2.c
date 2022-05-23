#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* cria_vetor(int tam);
int* multiplica_elementos();

int main()
{
	int i, tam1,tam2;
	// declarar dois ponteiros para buffer alocado
	int *vetor1, *vetor2, *vetor3;

	// definir tam1 e tam2
	printf("Informe o tam1 e tam2");
	scanf("%d %d", &tam1, &tam2);
	
	vetor1 = cria_vetor(tam1);
	vetor2 = cria_vetor(tam2);
	vetor3 = multiplica_elementos(vetor1, vetor2, tam1, tam2);

	for(i=0;i<tam1+tam2;i++)
	{
		printf("vetor3[%d]:%d\n",i, vetor3[i]);
	}
	// liberar espaços
	free(vetor1);
	free(vetor2);
	free(vetor3);

	return 0;
}

int* cria_vetor(int tam)
{
	int i;
	int* vetor;

	srand(time(NULL));

	vetor = (int*) malloc(tam*sizeof(int));

	for(i=0;i<tam;i++)
	{
		vetor[i] = rand()%10;
	}
	return vetor;
}

int* multiplica_elementos(int* vetor1, int* vetor2, int tam1, int tam2)
{
	int i, tam = tam1+tam2;
	int* vetor;

	vetor = (int*)malloc(tam*sizeof(int));

	for(i=0;i<tam;i++)
	{
		vetor[i] = vetor1[i]*vetor2[i];
	}
	return vetor;
}
