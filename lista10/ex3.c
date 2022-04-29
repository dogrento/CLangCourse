#include <stdio.h>


int proxFibo(int x)
{
	int primeiroTermo = 0;
	int segundoTermo = 1;
	int fiboFlag = 0;
	int proxTermo;
	
	while(fiboFlag == 0)
	{
		proxTermo = primeiroTermo + segundoTermo;		
		primeiroTermo = segundoTermo;
		segundoTermo = proxTermo;

		if(proxTermo >= x)
		{
			fiboFlag = 1;
		}
		
	}

	return proxTermo;
}

int main()
{
	int x;

	printf("Informe um valor:\n");
	scanf("%d", &x);
	printf("O valor da sequencia mais proximo de %d é %d\n", x, proxFibo(x));
	
	return 0;
}
