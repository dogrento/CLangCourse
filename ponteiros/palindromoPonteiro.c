#include <stdio.h>

// função que não sei
void removeExtremos(int *n, int *pri, int *ult)
{
	int tn , pot=1;
	
	// var recebe conteúdo apontado por *n
	tn = *n;
	printf("tn = %d\n", tn);

	// loop 
	while(tn >= 10)
	{
		tn = tn/10;
		printf("tn = %d\n", tn);

		pot *= 10;
		printf("pot * 10 = %d\n", pot);
	}

	// conteudo apontado por ___ será atualizado
	*pri = *n / pot;
	printf("%d\n", *pri);
	*ult = *n % 10;
	printf("%d\n", *ult);
	*n = *n % pot;
	printf("%d\n",*n);
	*n = *n / 10;
	printf("%d\n",*n);

}

int main()
{
	int n, i, eh_palindromo, head, tail;
	
	// armazenando conteudo no endereço de n
	scanf("%d", &n);
	
	// setando flag
	eh_palindromo = 1;

	while(n && eh_palindromo)
	{
		// chama função
		removeExtremos(&n, &head, &tail);

		if(head != tail)
			// atualiza flag
			eh_palindromo = 0;
	}

	if(eh_palindromo)
		printf("É palíndromo!\n");
	else
		printf("Não é palíndromo!\n");

	return 0;
}
