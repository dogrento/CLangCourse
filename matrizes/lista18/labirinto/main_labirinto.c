/*===========================================================================*/
/* LABIRINTO                                                                 */
/*===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*===========================================================================*/

#define FILENAME "teste1.txt"
#define CLEAR "cls" // Mude para "clear" no Linux.

#define BUFLEN 1024 // Altura/largura m�xima do labirinto + 2

#define PAREDE -2
#define CAMINHO -1

/*===========================================================================*/
/* FUN��ES                                                                   */
/*===========================================================================*/

int** carregaLabirinto (char* filename, int* w, int* h, int* x_rato, int* y_rato, int* x_queijo, int* y_queijo);
void mostraLabirinto (int** lab, int w, int h, int x_rato, int y_rato, int x_queijo, int y_queijo);
void preencheMatrizCusto (int** m, int w, int h, int x_queijo, int y_queijo);
void imprimeMatriz (int** m, int w, int h);
int calculaCaminho (int** m, int w, int h, int x_rato, int y_rato, int** caminho_x, int** caminho_y);
void mostraCaminho (int** m, int w, int h, int x_queijo, int y_queijo, int* caminho_x, int* caminho_y, int tam);

/*===========================================================================*/

int main ()
{
    int i;
    int **lab; // Matriz que representa o labirinto.
    int w, h; // Largura e altura do labirinto.
    int *caminho_x, *caminho_y; // Coordenadas x e y do caminho.
    int rato_x, rato_y; // Posi��o do rato.
    int queijo_x, queijo_y; // Posi��o do queijo.
    int tam; // Tamanho do caminho.

    lab = carregaLabirinto (FILENAME, &w, &h, &rato_x, &rato_y, &queijo_x, &queijo_y);
    if (!lab)
    {
        printf ("Erro abrindo %s\n", FILENAME);
        return 1;
    }

    preencheMatrizCusto (lab, w, h, queijo_x, queijo_y);
    tam = calculaCaminho (lab, w, h, rato_x, rato_y, &caminho_x, &caminho_y);
    mostraCaminho (lab, w, h, queijo_x, queijo_y, caminho_x, caminho_y, tam);

    // Desaloca tudo.
    for (i = 0; i < h; i++)
        free (lab [i]);
    free (lab);
    free (caminho_x);
    free (caminho_y);

    return 0;
}

/*---------------------------------------------------------------------------*/
/** L� o labirinto de um arquivo txt. Sup�e que est� tudo mais ou menos ok,
 * de acordo com a especifica��o (i.e. n�o estou testando muita coisa...).
 *
 * Par�metros: char* filename: arquivo para abrir.
 *             int* w, int* h: par�metros de sa�da, largura/altura do labirinto.
 *
 * Valor de retorno: uma matriz de int alocada dinamicamente, preenchida como
                     explicado na especifica��o do problema do labirinto. */

int** carregaLabirinto (char* filename, int* w, int* h, int* x_rato, int* y_rato, int* x_queijo, int* y_queijo)
{
    int i, j;
    char foostring [BUFLEN];
    FILE* f;
    int** m;

    f = fopen (filename, "r");
    if (!f)
        return NULL;

    // Inicializa o rato e o queijo.
    *x_rato = -1;
    *y_rato = -1;
    *x_queijo = -1;
    *y_queijo = -1;

    // L� a primeira linha.
    if (!fgets (foostring, BUFLEN, f))
        return NULL;
    *w = strlen (foostring)-1;
    foostring [*w] = 0;

    // Aloca a matriz com um n�mero tempor�rio de linhas "lixo".
    m = (int**) malloc (sizeof (int*) * BUFLEN);

    // Enquanto tiver linhas para ler, vai lendo!
    for (i = 0; foostring [0]; i++)
    {
        // Coloca a linha lida na matriz.
        m [i] = (int*) malloc (sizeof (int) * *w);
        for (j = 0; j < *w; j++)
        {
            // Rato? (n�o estou verificando se tem mais que 1 rato!)
            if (foostring [j] == 'r' || foostring [j] == 'R')
            {
                *y_rato = i;
                *x_rato = j;
                foostring [j] = ' ';
            }
            // Queijo? (n�o estou verificando se tem mais que 1 queijo!)
            else if (foostring [j] == 'q' || foostring [j] == 'Q')
            {
                *y_queijo = i;
                *x_queijo = j;
                foostring [j] = ' ';
            }

            if (foostring [j] == ' ')
                m [i][j] = CAMINHO;
            else
                m [i][j] = PAREDE;
        }

        // L� outra linha. N�o estou testando se est� do tamanho certo!
        if (!fgets (foostring, *w + 2, f))
            foostring [0] = 0; // Acabou.
        foostring [*w] = 0;
    }

    // Mant�m somente as linhas v�lidas.
    *h = i;
    m = realloc (m, sizeof (int*) * (*h));

    fclose (f);

    return (m);
}

/*---------------------------------------------------------------------------*/
/** Mostra o labirinto de um jeito "bonitinho".
 *
 * Par�metros: int** lab: labirinto (ou matriz de custo).
 *             int w, int h: largura/altura do labirinto.
 *             int x_rato, int y_rato: coordenadas do rato.
 *             int x_queijo, int y_queijo: coordenadas do queijo.
 *
 * Valor de retorno: nenhum. */

void mostraLabirinto (int** lab, int w, int h, int x_rato, int y_rato, int x_queijo, int y_queijo)
{
    int i, j;

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            if (i == y_rato && j == x_rato)
                printf ("R");
            else if (i == y_queijo && j == x_queijo)
                printf ("Q");
            else if (lab [i][j] == PAREDE)
                printf ("|");
            else
                printf (" ");
        }

        printf ("\n");
    }
}

/*---------------------------------------------------------------------------*/
/** Transforma a matriz dada em uma matriz de custo. Inicialmente, a matriz
 * cont�m somente os valores definidos pelas constantes PAREDE e CAMINHO, que
 * s�o negativos. A fun��o deve substituir as posi��es contendo o valor para
 * o CAMINHO pela dist�ncia L1 at� a posi��o do queijo.
 *
 * Par�metros: int** m: matriz de entrada e sa�da.
 *             int w, int h: largura/altura de m.
 *             int x_queijo, int y_queijo: coordenadas do queijo.
 *
 * Valor de retorno: nenhum. A matriz m tamb�m � modificada. */

void preencheMatrizCusto (int** m, int w, int h, int x_queijo, int y_queijo)
{
    // TODO: escreva esta fun��o!
}

/*---------------------------------------------------------------------------*/
/** Imprime uma matriz de inteiros na tela.
 *
 * Par�metros: int** m: matriz para mostrar.
 *             int w, int h: largura/altura da matriz.
 *
 * Valor de retorno: nenhum. */

// TODO: apenas leia: esta fun��o pode ser �til para testar alguma coisa. Se precisar, pode mudar o 3 do printf para ver valores maiores.

void imprimeMatriz (int** m, int w, int h)
{
    int i, j;

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
            printf ("%3d ", m[i][j]);
        printf ("\n");
    }
    printf("\n");
}

/*---------------------------------------------------------------------------*/
/** Gera 2 vetores que armazenam o caminho do rato at� o queijo, com base em
 * uma matriz de custo j� preenchida corretamente. Os vetores s�o gerados com
 * aloca��o din�mica, e devem ser desalocados pelo chamador.
 *
 * Par�metros: int** m: matriz de custo j� preenchida.
 *             int w, int h: largura/altura de m.
 *             int x_rato, int y_rato: coordenadas do rato.
 *             int** caminho_x, int** caminho_y: 2 ponteiros para os vetores de
 *               sa�da. Os vetores ser�o armazenados nesta fun��o, e v�o conter
 *               as coordenadas de cada posi��o do caminho, come�ando com a
 *               posi��o do rato e terminando com a posi��o do queijo.
 *
 * Valor de retorno: o tamanho do caminho (= n�mero de valores em caminho_x e
 *                   caminho_y). */

int calculaCaminho (int** m, int w, int h, int x_rato, int y_rato, int** caminho_x, int** caminho_y)
{
    // TODO: escreva esta fun��o!

    // Lembrete: para alocar um vetor de int em um ponteiro passado por refer�ncia:
    // *vetor = (int*) malloc (sizeof (int) * tamanho);
    //
    // Neste caso, lembre-se de resolver os dois endere�os ao usar o vetor:
    // (*vetor) [i]
    //
    // Se preferir, voc� pode alocar um vetor normalmente, e s� no final do processo atribuir o seu endere�o � vari�vel:
    // vetor = (int*) malloc (sizeof (int) * tamanho);
    // vetor [i] = ...
    // *vetor_passado_por_ref = vetor
}

/*---------------------------------------------------------------------------*/
/** Mostra o labirinto v�rias vezes, percorrendo o caminho.
 *
 * Par�metros: int** m: matriz de custo.
 *             int w, int h: largura/altura de m.
 *             int x_queijo, int y_queijo: coordenadas do queijo.
 *             int* caminho_x, int* caminho_y: coordenadas do caminho.
 *             int tam: tamanho do caminho.
 *
 * Valor de retorno: nenhum. */

void mostraCaminho (int** m, int w, int h, int x_queijo, int y_queijo, int* caminho_x, int* caminho_y, int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        system (CLEAR);
        mostraLabirinto (m, w, h, caminho_x [i], caminho_y [i], x_queijo, y_queijo);
        system ("pause");
    }
}

/*===========================================================================*/
