#include <stdio.h>

#define DADO 6

int main()
{
	int i, j, k, possibilidade=0;

	for(i=1 ; i <= DADO ; i++)
	{

		for(j=i ; j<=DADO ; j++)
		{

			for(k=j ; k<=DADO ; k++)
			{
				printf("%d, %d, %d\n", i, j, k);			
				possibilidade++;
			}
			possibilidade++;
		}
		possibilidade++;
	}

	printf("há %d possibilidades.\n ", possibilidade);

	return 0;
}
