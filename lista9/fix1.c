#include <stdio.h>

int main()
{
	int i, j;
	// Fazer um loop de 1 a 10
	for(i=1 ; i<=10 ; i++)
		{
		// Fazer outro loop de 1 a 10
		for(j=1 ; j<= 10 ; j++)
			printf("%d * %d = %d \n", i, j, i*j);
		printf("\n");
		}
		
 
	return 0;
}	
