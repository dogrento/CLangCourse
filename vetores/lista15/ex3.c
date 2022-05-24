#include <stdio.h>
#include <stdlib.h>

#define N  10

int presenteEm(int valor, int vetor[], int tam);
void print_vetor(int vetor[], int tam);

int filtro(int vetorInput[], int tam, int vetorOutput[])
{
	int i;
	int tamOutput = 0;

	// percorrer o vetorInput
	for(i=0;i<tam;i++)
	{
		if(!presenteEm(vetorInput[i], vetorOutput, tamOutput))	
			vetorOutput[tamOutput++] = vetorInput[i];
	}
	return tamOutput;
}

int main()
{
	int i;
	int vetor[N],
	    outroVetor[N];

	for(i=0;i<N;i++)
	{
		scanf("%d", &vetor[i]);
	}
	print_vetor(vetor, N);

	printf("%d\n", filtro(vetor, N, outroVetor));
	return 0;
}

/*FUNÇÕES AUXILIRES*/
int presenteEm(int valor, int vetor[], int tam)
{
	int i;
	for(i=0;i<tam;i++)
	{
		if(vetor[i]==valor)
			return 1;
	}
	return 0;
}


void print_vetor(int vetor[], int tam)
{
	int i;

	for(i=0;i<tam;i++)
	{
		printf("%d\n", vetor[i]);
	}
}


