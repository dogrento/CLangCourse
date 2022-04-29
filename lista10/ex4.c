#include <stdio.h>

// função unsigned de até 64 bits, entrada: base e expoente
unsigned long long potencia(unsigned int base, unsigned int expoente)
{
	// declarando um unsigned local de 64 bits
	unsigned long long total = 1;

	// declarando um int local (16 ~ 64 bits por padrão)
	int i;

	// loop FOR para que resulta a potencia
	for(i=1 ; i<=expoente ; i++)
	{
		total *= base;
	}

	// retorna resultado
	return (total);
}

int main()
{
	int base, expoente;
	long long unsigned result;

	printf("Informe o valor da base:\n");
	scanf("%d", &base);

	printf("Informe o valor do expoente:\n");
	scanf("%d", &expoente);

	result = potencia(base, expoente);

	printf("resultado:%llu\n", result);

	return 0;
}
