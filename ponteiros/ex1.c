#include <stdio.h>

// Função que transforma o total de segundos em formato H:M:S com ponteiros
void segundosParaHMS(int totalSegundos, int *h, int *m, int *s)
{
	// considere a tipagem e suas manipulações
	// conteudo apontado por *h recebe o valor da operação
	*h = totalSegundos / 3600;

	// atualiza a variavel
	totalSegundos = totalSegundos - (*h * 3600);

	// conteudo apontado por *m e *s recebe valor da operação 
	*m = totalSegundos / 60;	
	*s = totalSegundos % 60;
}

int main()
{
	int totalSegundos;
	int h, m, s;

	scanf("%d", &totalSegundos);
	
	// chamada da função
	// &h &m &s -> endereço de memoria das variáveis h m s
	segundosParaHMS(totalSegundos, &h, &m, &s);

	printf("%02d:%02d:%02d\n", h, m, s);

	return 0;
}
