#include <stdio.h>
#include <stdlib.h>

float lucro_total(Faccao* f){
	int i, j;
	float lucroTotal,
	      lucroTerri;

	for(i=0; i< f->n_territorios; i++){
		Territorio* t = f->territorios[i];

		lucroTerri = t->lucro_base;

		for(j=0; j< t->n_benfeitorias; j++){
			lucroTerri *= t->benfeitorias[j]->lucro_mult;
		}

		for(j=0; j< t->n_benfeitorias; j++){
			lucroTerri += t->benfeitorias[j]->lucro_soma;
		}

		for(j=0; j< t->exercitos[j]->custo;){
			lucroTerri -= t->exercitos[j]->custo;
		}
		lucroTotal += lucroTerri;
	}

	return lucroTotal;
}
