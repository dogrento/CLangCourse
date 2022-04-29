#include <stdio.h>

int arredonda(double x)
{
	int result;

	result = (int)(x*10.0) % 10;
	printf("%d\n", result);

	if(result>=5)
		return x+1;
	else if(result<5)
		return x;
	else
		return x;
}

int main()
{
	double var;
	printf("Informe um valor a ser arredondado: \n");
	scanf("%lf", &var);

	printf("%d\n", arredonda(var));

	return 0;
}
