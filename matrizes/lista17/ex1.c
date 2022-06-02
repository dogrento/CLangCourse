#include <stdio.h>
#include <stdlib.h>

#define LINHAS 3
#define COLUNAS 4

int main()
{
	int campo [LINHAS][COLUNAS] = {{81,28,240,10},
					{40,10,100,240},
					{20,180,110,35}};
	int i,j,soma,maior;

	soma = 0;
	for(i=0;i<LINHAS;i++)
	{
		for(j=0;j<COLUNAS;j++)
		{
			soma += campo[i][j];
			
		}
		if(soma>maior)
			maior=soma;
		soma = 0;
	}
	printf("soma = %d\n", maior);

	return 0;
}
