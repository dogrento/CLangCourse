#include <stdio.h>

#define N 5

int main()
{
	int div;

	// declarando flag para verificar se é primo;
	int flag = 1;

	// input;
	int n = 20;
	
	// loop para verificar se é primo;
	for(div=2 ; div < n ; div++)
	{
		// printando os valores até n;
		printf("%d\n", div);
		// se n for divisivel por ()  
		if(n%div==0)
		{
			//atualiza a flag
			flag = 0;

			printf("div: %d\n", div);
		}		
	}

	return 0;
}
