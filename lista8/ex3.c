#include <stdio.h>

int main()
{	
	int n, i;
	int term0 = 0, term1 = 1;
	int nextTerm = term0 + term1;

	// usr informa a quantidade de n para o fibbo
	printf("Informe o valor para n:\n");
	scanf("%d", &n);


	// n deve ser maior que maior igual a 3
	while(n<3)
	{
		printf("Valor inválido:\n");
		scanf("%d", &n);	
	}

	printf("Fibo serie: %d, %d, ", term0, term1);

	// retorna a sequencia
	for(i=3 ; i <= n ; ++i)
	{
		printf("%d, ", nextTerm);
		term0 = term1;
		term1 = nextTerm;
		nextTerm = term0 + term1;
	}


	return 0;
}

