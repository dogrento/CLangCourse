#include <stdio.h>
#include <string.h>

#define ANO 12

typedef struct{
	int valor,
	    dia;
	char nome[3];
	
}Mes;

int main(){

	Mes vetor[ANO];
	int i;
	
	for(i=0; i<ANO; i++){
		vetor[i].valor = i+1;
		printf("mes: %d\n", vetor[i].valor);
	}

	strcpy(vetor[0].nome, "JAN");
	strcpy(vetor[1].nome, "FEV");
	strcpy(vetor[2].nome, "MAR");
	strcpy(vetor[3].nome, "ABR");
	strcpy(vetor[4].nome, "MAI");
	strcpy(vetor[5].nome, "JUN");
	strcpy(vetor[6].nome, "JUL");
	strcpy(vetor[7].nome, "AGO");
	strcpy(vetor[8].nome, "SET");
	strcpy(vetor[9].nome, "OUT");
	strcpy(vetor[10].nome, "NOV");
	strcpy(vetor[11].nome, "DEZ");

	for(i=0; i<=6; i++){
		if(vetor[i].valor % 2 != 0)
			vetor[i].dia = 31;
		else{
			if(vetor[i].valor == 2)
				vetor[i].dia = 28;
			else
				vetor[i].dia = 30;
		}	
	}

	for(i=7; i<ANO; i++){
		if(vetor[i].valor % 2 == 0)
			vetor[i].dia = 31;
		else
			vetor[i].dia = 30;
	}

	for(i=0; i<ANO; i++){
		printf("%d: %s -> %d dias\n", vetor[i].valor, vetor[i].nome, vetor[i].dia);
	}

	return 0;

}
