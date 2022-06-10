#include <stdio.h>

typedef struct{
	int hora,
	    minuto,
	    segundo;
} Horario;

int segundo_entre(Horario h1, Horario h2){
	int result1,
	    result2;

	result1 = (h1.hora*3600)+(h1.minuto*60)+h1.segundo;
	result2 = (h2.hora*3600)+(h2.minuto*60)+h2.segundo;

	return result2 - result1;
}

int main(){
	Horario h1, h2;
	int result;

	printf("Informe um o primeiro horário:\n");
	scanf("%d %d %d", &h1.hora, &h1.minuto, &h1.segundo);

	printf("Informe um o segundo horário:\n");
	scanf("%d %d %d", &h2.hora, &h2.minuto, &h2.segundo);

	result = segundo_entre(h1, h2);
	printf("%d\n", result);

	return 0;
}
