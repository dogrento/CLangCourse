#include <stdio.h>
#include <stdlib.h>

#define LINHAS 3 
#define COLUNAS 128

int main()
{
	int i;
	char matriz[LINHAS][COLUNAS];

	for(i=0;i<LINHAS;i++)
	{
		scanf("%s", &matriz[i]);
	}
	
	for(i=LINHAS-1;i>=0;i--)
		printf("%s\n", matriz[i]);

	return 0;
}
