#include <stdio.h>

#define META 1000000

int main()
{
	int i, flag, qtDia, dia, acessos, total;

	// o usuario deve dar 2 entradas no mínimo:
	// a quantidade de dias que se passou;
	printf("Informe a quantidade de dias:\n");
	scanf("%d", &qtDia);
	
	// setando constantes
	flag = 0;
	total = 0;
	dia = -1;

	// a quantidade de acessos referente a quantidade de dias * LOOp
	for(i=1 ; i<= qtDia ; i++)
	{
		// somatoria dos acessos
		printf("Informe a valor dos acessos:\n");	
		scanf("%d", &acessos);

		total += acessos;
	       	printf("Total: %d\n", total);
		
		if(total > META && flag == 0)
		{
			dia = i;
			flag = 1;	
		}
	// deve retornar a quantidade de dias que foram necessarios para alcançar a meta = 1.000.000
	}

	printf("Dias necessários foram:%d\n", dia);

	return 0;
}
