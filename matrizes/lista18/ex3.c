#include <stdio.h>

#define N 5

int main()
{
	char matriz[N][N]={{'a', 'b', 'c', 'd', 'e'},
			   {' ', 'b', 'c', 'd', 'e'},
			      {' ', ' ', 'c', 'd', 'e'},
			      {' ', ' ', ' ', 'd', 'e'},
			      {' ', ' ', ' ', ' ', 'e'}};

	int i, j;

	for(i=0; i<N; i++)
	{
		printf("\n");
		for(j=0;j<N;j++)
		{
			printf("%d\t", matriz[i][j]);
		}
	}

		
}
