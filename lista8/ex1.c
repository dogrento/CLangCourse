#include <stdio.h>

int main()
{
	int num, i=1 ;
	// usuário apresenta valor
	scanf("%d", &num);

	// enquanto o valor for maior igual a 1 segue o laço
	while(num != 1)
	{	
		// se for par num = num / 2
		if(num % 2 == 0)
			num = num / 2;

		// se for impar num = num * 3 + 1  
		else
			num = num * 3 + 1;

		// atualiza contador
		i++;

		// printa num
		printf("%d, ", num);
	}
	printf("\nGerou %d elementos.\n", i);

	return 0;

}
