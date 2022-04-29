#include <stdio.h>

int ehProgressaoAritmetica(int n1,int n2,int n3,int n4)
{
	int razao;

	if(n4-n3==n3-n2 && n3-n2 == n2-n1)
	{
		razao = n2 - n1;
		printf("é pa com razão = %d\n", razao);
		return 1;
	}
	else
		return 0;
}

int main()
{
	int n1, n2, n3, n4, resposta;
	
	printf("Informe 4 valores:\n");
	scanf("%d %d %d %d", &n1, &n2, &n3, &n4);

	resposta = ehProgressaoAritmetica(n1, n2, n3, n4);

	if(resposta == 1)
		printf("\n");
	else
		printf("Não é PA\n");

	return 0;
}
