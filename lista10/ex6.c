#include <stdio.h>

int testaTipoChar(char c)
{
	if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
		return 1;

	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return 2;

	if(c > 'A' && c <= 'Z')
		return 3;

	if(c > 'a' && c <= 'z')
		return 4;

	if(c >= '0' && c <= '9')
		return 5;
}

int main()
{
	char c;
	int result;

	printf("Informe um char:\n");
	scanf("%c", &c);

	result = testaTipoChar(c);

	if(result == 1)
		printf("é uma vogal maiúscula\n");
	else if(result == 2)
		printf("é uma vogal minuscula\n");
	else if(result == 3)
		printf("é uma consoante caps\n");	
	else if(result == 4)
		printf("é uma consoante mini\n");
	else if(result == 5)
		printf("é um digito\n");

	else
		printf("sei la que porra\n");

}
