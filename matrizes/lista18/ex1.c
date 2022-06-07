#include <stdio.h>
#include <stdlib.h>

#define N 11

void zera_matriz(int matriz[][N], int n)
{
	int i, j;

	for (i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		{
			matriz[i][j]=0;
			printf("%d\t", matriz[i][j]);
		}
	}
	
}

void print_matriz(int matriz[][N],int n)
{
	int i,j;

	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		{
			printf("%d\t", matriz[i][j]);
		}
	}
}

int main()
{
	int i, 
	    j, 
	    valor = 0, 
	    deslocamento=0,
	    n = N-1;

	int matriz[N][N];
	
	zera_matriz(matriz, N);

	while(valor<=N*N-1)
	{
		for(j=deslocamento;j<N-deslocamento;j++)
		{
			matriz[deslocamento][j]=valor++;
		}

		for(i=deslocamento+1;i<=n-deslocamento;i++)
		{
			matriz[i][n-deslocamento]=valor++;
		}

		for(j=n-deslocamento-1;j>=deslocamento;j--)
		{
			matriz[n-deslocamento][j]=valor++;
		}

		for(i=n-deslocamento-1;i>deslocamento;i--)
		{
			matriz[i][deslocamento]=valor++;
		}
		deslocamento++;
	}

	printf("\n");	
	print_matriz(matriz, N);

	return 0;
}
