#include <stdio.h>

#define N 50

int main()
{
	int resposta, contador = 1;
	int max = N+1, min = 0;
	int palpite = (min + max ) / 2;
	int flag = 0;

	printf("Pense em um valor no intervalo entre %d a %d\n", min, N);

	while(flag == 0)
	{
		printf("o valor é maior[1], menor[2] ou igual[3] ao %d?\n", palpite);
		scanf("%d", &resposta);

		while(resposta < 1 || resposta > 3)
		{
			printf("Entrada inválida!\n");
			printf("o valor é maior[1], menor[2] ou igual[3] ao %d?\n", palpite);
			scanf("%d", &resposta);
		}

		if(resposta == 1)
		{
			printf("MAIOR\n");	
			min = palpite;
			palpite = (min + max) / 2;
			contador++;
		}
		if(resposta == 2)
		{
			printf("MENOR\n");	
			max = palpite;
			palpite = (max+min)/2;	
			contador++;
		}
		if(resposta == 3)
		{
			printf("IGUAL\n");	
			flag = 1;
		}
	}
	// testar se o palpite é maior ou menor que a constante
	printf("Tentativas: %d\n", contador);

	return 0;
}
