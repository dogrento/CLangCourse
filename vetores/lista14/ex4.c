#include <stdio.h>
#include <string.h>

// sequencia deve receber no max 50 char
#define MAX 50

int eh_vogal(char c);

// funç que deve retornar se sequencia de risos é engraçado ou não
int eh_funny(char* string)
{
	int tam, pos_left, pos_right;

	tam = strlen(string);

	// contador de posições nas duas direções
	pos_left = 0;
	pos_right = tam-1;

	// percorre até achar 2 vogais nos dois sentidos
	while(pos_left < pos_right)
	{
		// acha proxima vogal pela esquerda
		while(!eh_vogal(string[pos_left]))
			pos_left++;
		// acha proxima vogal pela direita
		while(!eh_vogal(string[pos_right]))
			pos_right--;

		if(string[pos_left] != string[pos_right])
			return 0;

		pos_left++;
		pos_right--;
	}

	return 1;
}

int eh_vogal(char c)
{
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int main()
{
	char string[MAX];
	scanf("%s", string);
	printf("%d\n", eh_funny(string));
	return 0;
}
