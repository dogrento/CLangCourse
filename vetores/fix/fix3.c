#include <stdio.h>
#define N 10

int main()
{
	int i;
	int numeros[N];

	for(i=0 ; i<N ; i++)
	{
		scanf("%d", &numeros[i]);
		//numeros[i]=n;
	}
	
	// imprime os que estão em posição pares
	for(i=0 ; i<N ; i+=2)
	{
		printf("vetor[%d]\n", numeros[i]);
	}
	// imprime os que estão em posição impares
	for(i=1 ; i<N ; i+=2)
	{
		printf("vetor[%d]\n", numeros[i]);
	}	
	
	return 0;
}
