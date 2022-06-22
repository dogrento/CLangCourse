#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int numero;
	char* nome;
	char* email;
	char* endereco;
	int** prova;
	float nota;
} Candidato;

void corrige_prova(Candidato* c, int** gabarito, int nQuestao, int nItens){
	int i, j, acertos, erros;
	float peso_por_item = 100/((float) nQuestao * nItens);

	c->nota = 0;

	for(i=0; i< nQuestao; i++){
		acertos = 0;
		erros = 0;

		for(j=0; j< nItens; j++){
			if(c->prova[i][j] == 0 || c->prova[i][j] == 1){
				if(c->prova[i][j] == gabarito[i][j]){
					acertos++;
				}
			        else
					erros++;
			}
		}

		if(erros < acertos)
			c->nota += (peso_por_item * (acertos - erros));
	}

}

int main(){
	return 0;
}
