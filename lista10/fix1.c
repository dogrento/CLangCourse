#include <stdio.h>

int ehBissexto(int ano)
{
	if(ano%100!=0 && ano%4==0)
		return 1;
	else if(ano%400==0)
		return 1;
	else
		return 0;
}

int main()
{
	int ano, resposta;

	scanf("%d", &ano);

	resposta = ehBissexto(ano);

	if(resposta == 1)
		printf("O ano %d é bissexto\n", ano);
	else
		printf("O ano %d não é bissexto\n", ano);

	return 0;
}
