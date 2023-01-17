#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  int coluna;
  int elemento;
} TipoItem;

struct noh{
  TipoItem item;
  struct noh *prox;
};

typedef struct noh TipoNoh;

typedef TipoNoh *TipoLista;

int listaVazia(TipoLista);
TipoLista inicializaLista(TipoLista);
TipoLista destroiLista(TipoLista);
void imprimeItem(TipoItem);
int imprimeLista(TipoLista, int);
TipoLista insereNoFinalAdaptado(TipoLista,TipoItem);
TipoLista insereNoInicio(TipoLista,TipoItem);
TipoLista removeDoFinal(TipoLista,TipoItem*);
TipoLista removeDoInicio(TipoLista,TipoItem*);
TipoLista ordenaLista(TipoLista, int);
int RemoveNaPosicao(TipoLista, int);