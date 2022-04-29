#include <stdio.h>

#define LARGURA_FAIXA 6 // em cm

// funç para o rolo azul
int pontoRolo1()
{
	printf("A");
}

// funç para linha vermelha
int pontoRolo2()
{
	printf("V");
}

// funç para mover aglha
int moveAgulha()
{
	printf(" ");
}

// funç para rola tecido
int rolaTecido()
{
	printf("\n");
}

void main ()
{
	int i;
	/* Funciona até desligar ou o tecido acabar. */
	while (1)
	{
		for (i = 0; i < LARGURA_FAIXA; i++)
		{
			if (i == 1)
				pontoRolo1 ();
			else if (i == LARGURA_FAIXA-2)
				pontoRolo2 ();
			else
				moveAgulha ();
		}

		rolaTecido ();
	}
}
