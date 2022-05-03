#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_VETOR 10
#define INTERVALO 80

int main()
{
	int media, i, vetor[TAM_VETOR], somaPositivo=0, qtPositivo = 0;
	srand(time(NULL));

	for(i=0 ; i<TAM_VETOR ; i++)
	{
		vetor[i] = rand()%INTERVALO-40;

		if(vetor[i]>=0)
		{
			printf("valores positivos: %d\n", vetor[i]);
			somaPositivo += vetor[i]; 
			qtPositivo++;
		}
	}
	media = somaPositivo / qtPositivo;
	printf("quantidade de positivos: %d\n media: %d\n", qtPositivo, media);

	return 0;
}
