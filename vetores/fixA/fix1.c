#include <stdio.h>


#define LMT 10 // definindo a macro usa para limitar o vetor

int main()
{
	int i, v[LMT];
	
	// para cada i
	for(i = 0 ; i < LMT ; i++)
	{
		// posição do vetor será igual a i+1
		v[i]=i+1;
		// retorna a posição do vetor e a sua value
		printf("v[%d]: %d\n", i, v[i]);
	}	
	return 0;
}
