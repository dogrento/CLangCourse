#include <stdio.h>
#include <stdlib.h>

#define N 5

int main()
{
	char matriz[N][N]={{'a', 'b', 'c', 'd', 'e'},
			   {' ', 'b', 'c', 'd', 'e'},
			      {' ', ' ', 'c', 'd', 'e'},
			      {' ', ' ', ' ', 'd', 'e'},
			      {' ', ' ', ' ', ' ', 'e'}};
	// criando ponteira para ponteiro para alocar dinamicamente a matriz
	char **output;

	int i, j;

	for(i=0; i<N; i++)
	{
		printf("\n");
		for(j=0;j<N;j++)
		{
			printf("%c\t", matriz[i][j]);
		}
	}
	
	// alocando memoria para a primeira "camada" da matriz
	output = (char**) malloc((N * 2) * sizeof(char*));

	//alocando para a segunda camada
	for(i=0; i< N*2; i++)
	{
		output[i] = (char*) malloc((N*2) * sizeof(char));
	}

	puts("\n");

	for(i=0; i<N; i++){
		for(j=0 ; j<N ; j++){
			output[i][j] = matriz[i][j];
			output[i][N*2-j-1] = matriz[i][j];
			output[N*2 -i -1][j] = matriz[i][j];
			output[N*2 -i -1][N*2 -j -1] = matriz[i][j];
		}
	}

	for(i=0; i<N*2; i++){
		puts("\n");
		for(j=0; j< N*2; j++){
			printf("%c\t", output[i][j]);
		}
	}

	// liberar espaço alocado
	for(i=0; i<N*2; i++){
		free(output[i]);
	}
	free(output);


	return 0;	
}
