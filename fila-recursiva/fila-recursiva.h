#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char primeiro_char;
    char ultimo_char;
} TipoItemFila;

struct nohfila {
    TipoItemFila item;
    struct nohfila *prox;
};

typedef struct nohfila TipoNohFila;

typedef struct nohfila* TipoFilaRecursiva;

TipoFilaRecursiva InsereFila(TipoFilaRecursiva, TipoItemFila);