#include <stdio.h>

unsigned int invertNum(unsigned int n)
{
	int invertido = 0;

	while(n > 0)
	{
		invertido = invertido*10;
		printf("invertido*10 = %d\n", invertido);
		invertido = invertido + n%10;	
		printf("invertido + resto de n por 10 = %d\n", invertido);

		n /= 10; // n = n / 10
		printf("N = %d\n", n);
	}

	return (invertido);
}

int main()
{
	unsigned int n;

	printf("Informe um valor:\n");
	scanf("%d", &n);

	printf("resultado: %d\n", invertNum(n));

	return 0;
}
