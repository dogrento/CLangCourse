#include <stdio.h>

// limite do vetor
#define N 81 

int main()
{
	int i, qtQuestao, count=0;

	// declarando vetores tipo char
	char gabarito[N], respostas[N];
	
	// ler do teclado a quantidade de questao
	printf("Informe o quantidade de questoes:\n");
	scanf("%d", &qtQuestao);

	printf("Informe o gabarito:\n");
	// armazenar char no vetor de gabarito
	for(i=0 ; i<qtQuestao ; i++)
	{
		scanf("%s", &gabarito[i]);
	}

	// armazenar char no vetor de respostas
	printf("Informe as respostas:\n");
	for(i=0 ; i<qtQuestao ; i++)
	{
		scanf("%s", &respostas[i]);
	}

	// comparar e informar os valores coincidentes
	for(i=0 ; i<qtQuestao ; i++)
	{
		if(gabarito[i]==respostas[i])
			count++;
	}
	printf("quantidades de respostas coincidentes:%d\n", count);
}

