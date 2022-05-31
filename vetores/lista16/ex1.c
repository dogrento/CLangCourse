#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFLEN 1024

char* empacotaString(char* string)
{
	// declaração do indice
	int i;
	// declaração do vetor onde será armazenado os char válidos
	char* string_empacotada;
	// declaração e inicialização do tamanho da string	
	int tamString = strlen(string);

	// no vetor receberá o novo tamanho
	string_empacotada = (char*)malloc(sizeof(char)*(tamString+1));

	// atribuindo valor ao novo vetor
	for(i=0;i<tamString;i++)
	{
		string_empacotada[i] = string [i]; 
	}
	return string_empacotada;					
		
}

int main()
{
	int i;
	char string[BUFLEN] = {"batata"};
	char* novaString;

	printf("dentro da main %s\n", string);

	novaString = empacotaString(string);

	printf("%s\n", novaString);	

	free(novaString);

	return 0;
}
