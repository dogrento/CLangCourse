#include <stdio.h>
#include<string.h>

#define BUFLEN 2048

int ehPalindromo(char *string)
{
	int i;
	int tam = strlen(string);

	for(i=0;i<tam/2;i++)
	{
		if(string[i] != string[tam-1-i])
			return (0);
	}
	return (1);
}

int main()
{
	char string[BUFLEN];

	fgets(string, BUFLEN, stdin);
	string[strlen(string)-1]=0;
	printf("%d\n", ehPalindromo(string));

	return 0;
}
