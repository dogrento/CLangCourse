#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFLEN 1024

char* concatena_string(char string1[], char string2[])
{
	int i, j, tam;
	char* novaString;
	// gerar o tamanho da nova string
	tam = strlen(string1)+strlen(string2);
	printf("%d\n", strlen(string1));
	printf("%d\n", strlen(string2));
	//alocar espaço
	novaString = (char*) malloc(tam*sizeof(char));	
	// concatenar as strings
	for(i=0;i<strlen(string1);i++)
	{
		novaString[i] = string1[i];
		printf("%c\n", novaString[i]);
	}
	j = 0;
	for(i=strlen(string1);i<tam;i++)
	{
		novaString[i] = string2[j++];
		printf("%c\n", novaString[i]);
	}
	// retornar stringConcatenada
	return novaString;
}

int main()
{
	char string1[BUFLEN], string2[BUFLEN], *stringConcatenada;
	scanf("%s %s", &string1, &string2);

	stringConcatenada = concatena_string(string1, string2);

	printf("%s\n", stringConcatenada);

	free(stringConcatenada);

	return 0;
}
