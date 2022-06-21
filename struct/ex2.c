#include <stdio.h>

#include <stdlib.h>

#define LARG 10
#define ALTU 10
// struct
typedef struct{
	int largura,
	    altura;
	unsigned char** dados;
}GSImage;

GSImage* criaGSImage(int largura, int altura)
{
	int i;
	GSImage* img;

	// alocar espaço para a imagem
	img = (GSImage*) malloc(sizeof(GSImage));

	// atribuir a largura e altura
	img->largura = largura;
	img->altura = altura;

	// alocar a matriz de dados
	img->dados = (unsigned char**) malloc(sizeof(unsigned char*) * altura);
	for(i=0;i<altura; i++){
		img->dados[i] = (unsigned char*) malloc(sizeof(unsigned char) * largura);
	}	
	// retornar o ponteiro
	return img;
}

GSImage* reduz_metade(GSImage* img){
	int i,
	    j;
	GSImage* reduzida;

	// tratamento de erro
	if(img->altura % 2 || img->largura % 2){
		return NULL;
	}

	reduzida = criaGSImage(img->largura/2, img-> altura/2);

	for(i=0; i< reduzida->altura; i++){
		for(j=0; j< reduzida->largura; j++){
			reduzida->dados[i][j] = (img->dados[i*2][j*2] +
						 img->dados[i*2][j*2+1] +
						 img->dados[i*2+1][j*2] +
						 img->dados[i*2+1][j*2+1])/4;
		}
	}
	return reduzida;
}

void f(){
	int i, j;
	GSImage* img, *reduzida;
	float media1, media2;

	img = criaGSImage(LARG, ALTU);

	for(i=0; i< ALTU; i++){
		for(j=0; j< LARG; j++){
			img->dados[i][j] = i*j;
		}
	}

	reduzida = reduz_metade(img);

	media1 = 0;
	for(i=0; i< img->altura; i++){
		for(j=0; j< img->largura; j++){
			media1 += img->dados[i][j];
		}
	}
	media1 /= (img->altura * img->largura);

	media2 = 0;
	for(i=0; i< reduzida->altura; i++){
		for(j=0; j< reduzida->largura; j++){
			media2 += reduzida->dados[i][j];
		}
	}
	media2 /=(reduzida->altura * reduzida->largura);

	printf("m1: %.2f , m2: %.2f", media1, media2);

}

int main(){
	puts("oi");
	return 0;
}
