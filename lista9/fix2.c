#include <stdio.h>

int main()
{
	int num, i, j;

	printf("Informe um valor:\n");
	scanf("%d", &num);

	for(j=1 ; j<=num ; j++)
	{	
		printf("\n");
		for(i=j; i<=num ; i++)
		{	
			printf("A");
		}
	}	

	return 0;
}	
