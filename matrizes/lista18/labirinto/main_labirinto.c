/*===========================================================================*/
/* LABIRINTO                                                                 */
/*===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*===========================================================================*/

#define FILENAME "teste1.txt"
#define CLEAR "cls" // Mude para "clear" no Linux.

#define BUFLEN 1024 // Altura/largura máxima do labirinto + 2

#define PAREDE -2
#define CAMINHO -1

/*===========================================================================*/
/* FUNÇÕES                                                                   */
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
    int rato_x, rato_y; // Posição do rato.
    int queijo_x, queijo_y; // Posição do queijo.
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
/** Lê o labirinto de um arquivo txt. Supõe que está tudo mais ou menos ok,
 * de acordo com a especificação (i.e. não estou testando muita coisa...).
 *
 * Parâmetros: char* filename: arquivo para abrir.
 *             int* w, int* h: parâmetros de saída, largura/altura do labirinto.
 *
 * Valor de retorno: uma matriz de int alocada dinamicamente, preenchida como
                     explicado na especificação do problema do labirinto. */

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

    // Lê a primeira linha.
    if (!fgets (foostring, BUFLEN, f))
        return NULL;
    *w = strlen (foostring)-1;
    foostring [*w] = 0;

    // Aloca a matriz com um número temporário de linhas "lixo".
    m = (int**) malloc (sizeof (int*) * BUFLEN);

    // Enquanto tiver linhas para ler, vai lendo!
    for (i = 0; foostring [0]; i++)
    {
        // Coloca a linha lida na matriz.
        m [i] = (int*) malloc (sizeof (int) * *w);
        for (j = 0; j < *w; j++)
        {
            // Rato? (não estou verificando se tem mais que 1 rato!)
            if (foostring [j] == 'r' || foostring [j] == 'R')
            {
                *y_rato = i;
                *x_rato = j;
                foostring [j] = ' ';
            }
            // Queijo? (não estou verificando se tem mais que 1 queijo!)
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

        // Lê outra linha. Não estou testando se está do tamanho certo!
        if (!fgets (foostring, *w + 2, f))
            foostring [0] = 0; // Acabou.
        foostring [*w] = 0;
    }

    // Mantém somente as linhas válidas.
    *h = i;
    m = realloc (m, sizeof (int*) * (*h));

    fclose (f);

    return (m);
}

/*---------------------------------------------------------------------------*/
/** Mostra o labirinto de um jeito "bonitinho".
 *
 * Parâmetros: int** lab: labirinto (ou matriz de custo).
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
 * contém somente os valores definidos pelas constantes PAREDE e CAMINHO, que
 * são negativos. A função deve substituir as posições contendo o valor para
 * o CAMINHO pela distância L1 até a posição do queijo.
 *
 * Parâmetros: int** m: matriz de entrada e saída.
 *             int w, int h: largura/altura de m.
 *             int x_queijo, int y_queijo: coordenadas do queijo.
 *
 * Valor de retorno: nenhum. A matriz m também é modificada. */

void preencheMatrizCusto (int** m, int w, int h, int x_queijo, int y_queijo)
{
    // TODO: escreva esta função!
}

/*---------------------------------------------------------------------------*/
/** Imprime uma matriz de inteiros na tela.
 *
 * Parâmetros: int** m: matriz para mostrar.
 *             int w, int h: largura/altura da matriz.
 *
 * Valor de retorno: nenhum. */

// TODO: apenas leia: esta função pode ser útil para testar alguma coisa. Se precisar, pode mudar o 3 do printf para ver valores maiores.

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
/** Gera 2 vetores que armazenam o caminho do rato até o queijo, com base em
 * uma matriz de custo já preenchida corretamente. Os vetores são gerados com
 * alocação dinâmica, e devem ser desalocados pelo chamador.
 *
 * Parâmetros: int** m: matriz de custo já preenchida.
 *             int w, int h: largura/altura de m.
 *             int x_rato, int y_rato: coordenadas do rato.
 *             int** caminho_x, int** caminho_y: 2 ponteiros para os vetores de
 *               saída. Os vetores serão armazenados nesta função, e vão conter
 *               as coordenadas de cada posição do caminho, começando com a
 *               posição do rato e terminando com a posição do queijo.
 *
 * Valor de retorno: o tamanho do caminho (= número de valores em caminho_x e
 *                   caminho_y). */

int calculaCaminho (int** m, int w, int h, int x_rato, int y_rato, int** caminho_x, int** caminho_y)
{
    // TODO: escreva esta função!

    // Lembrete: para alocar um vetor de int em um ponteiro passado por referência:
    // *vetor = (int*) malloc (sizeof (int) * tamanho);
    //
    // Neste caso, lembre-se de resolver os dois endereços ao usar o vetor:
    // (*vetor) [i]
    //
    // Se preferir, você pode alocar um vetor normalmente, e só no final do processo atribuir o seu endereço à variável:
    // vetor = (int*) malloc (sizeof (int) * tamanho);
    // vetor [i] = ...
    // *vetor_passado_por_ref = vetor
}

/*---------------------------------------------------------------------------*/
/** Mostra o labirinto várias vezes, percorrendo o caminho.
 *
 * Parâmetros: int** m: matriz de custo.
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
