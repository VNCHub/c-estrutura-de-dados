#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 30

typedef struct{
  int chave;
  char nome[TAM];
} TipoItem;

struct noh{
  TipoItem item;
  struct noh *prox;
};

typedef struct noh TipoNoh;

typedef struct{
  TipoNoh *inicioLista;
  int ultimo;
} ListaLinearED;

int listaVaziaLLED(ListaLinearED*);
void inicializaListaLLED(ListaLinearED*);
void destroiListaLLED(ListaLinearED*);
void imprimeItemLLED(TipoItem);
void imprimeListaLLED(ListaLinearED*);
int insereNoFinalLLED(ListaLinearED*,TipoItem);
int insereNoInicioLLED(ListaLinearED*,TipoItem);
int removeDoFinalLLED(ListaLinearED*,TipoItem*);
int removeDoInicioLLED(ListaLinearED*,TipoItem*);
int AdicionaNaPosicaoLLED(ListaLinearED *lista, TipoItem *item, int pos);
int RemoveNaPosicaoLLED(ListaLinearED *lista, int pos);
int RemoveEspecificoLLED(ListaLinearED *lista, TipoItem item);
int ERROlistaVaziaLLED(ListaLinearED *lista);