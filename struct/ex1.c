#include <stdio.h>

typedef struct{
	float maior,
	      menor,
	      meio;
}MaMeMe;

float classifica(float n1, float n2, float n3){
	MaMeMe valor;

	if(n1 > n2 && n1 > n3)
	{
		if(n2>n3)
		{
			valor.maior = n1;
			valor.meio = n2;
			valor.menor = n3;
		}

	}


	return valor.maior;
}

int main(){

	float n1, n2, n3;
	MaMeMe result;

	n1=3;
	n2=0;
	n3=0;
	
	result.maior = classifica(n1, n2, n3);
	printf("result: %f", result.maior);
}
