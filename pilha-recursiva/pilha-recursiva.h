#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nohpilha {
    char item;
    struct nohpilha *prox;
};

typedef struct nohpilha NohPilha;

typedef struct {
    NohPilha *topo;
} TipoPilha;

int Empilha(TipoPilha*, char);
int Desempilha(TipoPilha*);