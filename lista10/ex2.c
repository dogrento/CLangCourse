#include <stdio.h>

double casasDecimais(double x)
{
	return x - (int)x;
}

int main()
{
	double x;

	printf("Informe um valor double: \n ");
	scanf("%lf", &x);
	printf("resposta: %.1lf\n", casasDecimais(x));

	return 0;
}
