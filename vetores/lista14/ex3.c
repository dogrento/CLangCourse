#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OFFSET_R_L ('R' - 'L')
#define BUFFLEN 1024

void stling(char string[], char* s_cebolinha);
int eh_letra(char c);

int main()
{
	char string [BUFFLEN];
	char cebolinha[BUFFLEN];

	fgets(string, BUFFLEN, stdin);
	// remove o '\n'
	string[strlen(string)-1] = 0;

	stling(string, cebolinha);
	printf("%s\n", cebolinha);
}

void stling(char string[], char* s_cebolinha)
{
	int i, pos_cebolinha = 0;
	// definir o tamanho do novo vetor
	int tam = strlen(string);
	// percorrer o vetor em busca do R
	for(i=0 ; i<tam ; i++)
	{
		// verifica se a letra é R ou r e não está no final da palavra
		if((string[i] == 'R' || string[i] == 'r') && eh_letra(string[i+1]))
		{
			// se o char anterior for um R/r troca por L/l
			if((i == 0) || (string[i-1] != 'R' && string[i-1] != 'r'))	
				s_cebolinha[pos_cebolinha++] = string[i] - OFFSET_R_L;
		}
		else
			s_cebolinha[pos_cebolinha++] = string[i];
	}
	s_cebolinha[pos_cebolinha] = 0;
}

// funç auxiliar 
int eh_letra(char c)
{
	return((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
