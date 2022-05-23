#include <stdio.h>

// limite 1~100
#define LIM 99

int main()
{
	int i,
	    j,
	    nPedras,
	    mSapos, 
	    dist, 
	    pos;
	// inicializando vetores
	int sapos[LIM],
	    pedras[LIM];

	// recebe como entrada dois int	
	// quantidade de pedras
	printf("Informe a quantidade de pedras:\n");
	scanf("%d", &nPedras);
	// quantidade de sapos
	printf("Informe a quantidade de sapos:\n");
	scanf("%d", &mSapos);

	// inica o vetor pedras com 0 em todas a posições
	for(i=0; i<nPedras;i++)
	{
		pedras[i] = 0;	
	}
	
	// para cada sapo, serão lidos M pares de valores, a posição inicial e a quantidade de casas que serão puladas
	for(i=0;i<mSapos;i++)
	{
		printf("Informe a posinicial e distancia dos saltos:\n");
		scanf("%d", &pos);		
		scanf("%d", &dist);		

		for(j=pos;j<=nPedras;j=j+dist)
		{
			pedras[j]=1;			
			printf("pedras[%d]:%d\n", j, pedras[j]);
		}
		for(j=pos;j<=0;j=j-dist)
		{
			pedras[j]=1;
			printf("pedras[%d]:%d\n", j, pedras[j]);
		}
	}

	for(i=0;i<nPedras;i++)
	{
		printf("pedras[%d]:%d\n",i,pedras[i]);
	}

	return 0;
}
