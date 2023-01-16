#include "fila-recursiva.h"

TipoFilaRecursiva InsereFila(TipoFilaRecursiva fila, TipoItemFila item){
    TipoNohFila *novonoh;
    if(fila == NULL){
        novonoh = (TipoNohFila*) malloc(sizeof(TipoNohFila));
        novonoh->item = item;
        novonoh->prox = NULL;
        return novonoh;
    } else {
        fila->prox = InsereFila(fila->prox, item);
        return fila;
    }
}

//Falta demais funções