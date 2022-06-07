#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 3
#define COLUNAS 2

int main ()
{
	int i, j;
	int matriz[LINHAS][COLUNAS];
	int transposta[COLUNAS][LINHAS];
	srand(time(NULL));
	
	for(i=0;i<LINHAS;i++)
	{
		printf("\n%d: ", i);
		for(j=0;j<COLUNAS;j++)
		{
			matriz[i][j] = 1+(rand()%20);
			printf("%d\t", matriz[i][j]);
		}	
	}
	printf("\n");

	printf("*****\n");

	for(i=0;i<COLUNAS;i++)
	{
		for(j=0;j<LINHAS;j++)
		{
			transposta[i][j]= matriz[j][i];
			printf("%d\t", transposta[i][j]);
		}
		printf("\n");
	}

	return 0;
}


