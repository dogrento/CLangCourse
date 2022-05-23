#include <stdio.h>

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
}

int main()
{
	
}
