#include <stdio.h>

int main()
{
	int num, i;

	printf("Informe um valor:\n");
	scanf("%d", &num);

	for(i=0 ; i < num ; i++)
	{
		printf("%c", 'A'+i);
	}
	printf("\n");

	return 0;
}	
