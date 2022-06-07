#include <stdio.h>
#include <stdlib.h>

#define M 2
#define N 3


void multiplica_matriz(int matrizA[][N], int matrizB[][M],matrizOutput[][N], int M, int N)
{
	int i, j;
}

int main()
{
	int i,j;
	// declarar 3 matrizes: A, B, output
	int matrizA[M][N], matrizB[N][M], output[N][N];
	// atribuir valores à duas matrizes
	// matriz A:
	printf("Matriz A:\n");
	for(i=0;i<M;i++)
	{
		printf("\n");
		for(j=0;j<N;j++)
		{
			matrizA[i][j]=rand()%10;
			printf("%d\t",matrizA[i][j]);
		}
	}

	printf("\n\nMatriz B:\n");

	for(i=0;i<N;i++)
	{
		printf("\n");
		for(j=0;j<M;j++)
		{
			matrizB[i][j]=rand()%10;
			printf("%d\t",matrizA[i][j]);
		}
	}

	return 0;
}
