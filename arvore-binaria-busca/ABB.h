#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRINT_FORMAT "%d"
#define PRINT_FORMAT_WITH_SPACE " %d"

struct nohArvore{
    int dado;
    struct nohArvore *SE;
    struct nohArvore *SD;
};

typedef struct nohArvore TipoNohArvore;

typedef TipoNohArvore *TipoArvore;

TipoArvore instanciaArvore(int item);
TipoArvore insereValor(TipoArvore arvore, int item);
int imprimePreOrdem(TipoArvore noh, int n);
int imprimeEmOrdem(TipoArvore noh, int n);
int imprimePosOrdem(TipoArvore noh, int n);
int pesquisaExiste(TipoArvore arvore, int item);
TipoArvore removeArvore(TipoArvore noh, int item);
int procuraMaior(TipoArvore noh, int item);