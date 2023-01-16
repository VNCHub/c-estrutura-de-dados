#include "pilha-recursiva.h"

int Empilha(TipoPilha *pilha, char num)
{
    NohPilha *novonoh;
    novonoh = (NohPilha*)malloc(sizeof(NohPilha));
    if (novonoh != NULL)
    {
        novonoh->item = num;
        novonoh->prox = pilha->topo;
        pilha->topo = novonoh;
        return 1;
    }
    return 0;
}

int Desempilha(TipoPilha *pilha)
{
    int num;
    NohPilha *ptraux;
    ptraux = pilha->topo;
    pilha->topo = pilha->topo->prox;
    num = ptraux->item;
    free(ptraux);
    return num;
}
