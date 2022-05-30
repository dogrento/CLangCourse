#include <stdio.h>

#define N_LINHAS 7
#define N_COLUNAS 5

int main()
{

	int i, j;
	int matriz[N_LINHAS] [N_COLUNAS];

	for(i=0;i<N_LINHAS;i++)
	{
		for(j=0;j<N_COLUNAS;j++)
		{
			matriz[i][j]=i*j;
			printf("%d ",matriz[i][j]);
		}
		printf("\n");
	}
	return 0;
}
