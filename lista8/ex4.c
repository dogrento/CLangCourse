#include <stdio.h>

int main()
{
	int num, flag, i, var;
	int valores = 0, flag = 0;

	// usr deve informar a quantidade de variação relacionado ao tamanho da montanha
	printf("Informe o valor da variação:\n");
	scanf("%d", &num);

	// usr deve informar os valores de cada variação de acordo com o num anterior 
	for(i=1 ; i<=num ;i++)
	{
		printf("Informe os valores da variação:\n");
		scanf("%d", &var);

		valores = valores + var;
	}
	// se houver uma sequencia onde os valores sobem e desce, a flag mantem o status 
	return 0;
}
