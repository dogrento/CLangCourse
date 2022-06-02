#include <stdio.h>
#include <stdlib.h>

#define N 6

void print_matriz(int matriz[][N], int linhas, int colunas)
{
	int i,j;
	for(i=0;i<linhas;i++)
	{
		for(j=0;j<colunas;j++)
		{
			printf("%d\t", matriz[i][j]);
		}
		printf("\n");
	}
}


int main()
{
	int tabuleiro [N][N];
	int i, j;

	for(i=0;i<N;i++)
		tabuleiro[0][i] = rand()%2;
	for(i=1;i<N;i++)
	{
		tabuleiro[i][0] = rand()%2;

		for(j=1;j<N;j++)
		{
			tabuleiro[i][j]=9;
		}

	}
	print_matriz(tabuleiro, N, N);
	printf("\n");

	for(i=1;i<N;i++)
	{
		for(j=1;j<N;j++)
		{
			if(tabuleiro[i-1][j-1]+
			   tabuleiro[i-1][j]  +
			   tabuleiro[i][j-1]  >= 2 )
			{
				tabuleiro[i][j]=0;
			}
			else
				tabuleiro[i][j]=1;
		}
	}

	print_matriz(tabuleiro, N, N);

	return 0;
}


