#include <stdio.h>
#include <stdlib.h>

#define N 100

int eh_char(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int conta_palavras(char string[])
{
	int i;
	int countPalavras = 0;

	for(i=0;string[i]!= '\0';i++)
		if(eh_char(string[i]) && !eh_char(string[i+1]))
			countPalavras++;
	return countPalavras;
}

int main()
{
	int count;
	char string[N];
	fgets(string, N, stdin);
	
	count = conta_palavras(string);

	printf("%d\n", count);

	return 0;
}
