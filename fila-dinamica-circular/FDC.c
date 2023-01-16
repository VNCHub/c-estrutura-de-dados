#include "FDC.h"

void inicializaFila(TipoFila *fila){
  fila->n = 0;
  fila->fim = NULL;
}

void destroiFila(TipoFila *fila){
  TipoItem item;
  while(!filaVazia(fila))
    retiraDaFila(fila,&item);
}

int filaVazia(TipoFila *fila){
  return fila->n==0;
}

int insereNaFila(TipoFila *fila,TipoItem item){
  TipoNoh *novoNoh;
  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  if(novoNoh!=NULL){
    if(filaVazia(fila)){
      fila->fim = novoNoh;
      novoNoh->prox = fila->fim;
    }
    else{
      novoNoh->prox = fila->fim->prox;
      fila->fim->prox = novoNoh;
      fila->fim = novoNoh;
    }

    novoNoh->item = item;
    fila->n++;

    return 1;
  }
  return 0;
}

int retiraDaFila(TipoFila *fila,TipoItem *item){
  TipoNoh *ptrAux;
  if(!filaVazia(fila)){
    
    return 1;
  }
  return 0;
}

int imprimeFila(TipoFila *fila){
  TipoNoh *ptrAux;
  if(!filaVazia(fila)){
    ptrAux = NULL;
    while(ptrAux != fila->fim){
      if (ptrAux == NULL)
        ptrAux = fila->fim;
      ptrAux = ptrAux->prox;
      printf("Chave: %03d | Nome: %s\n", ptrAux->item.chave, ptrAux->item.nome);
      
    }
    return 1;
  }
  return 0;
}

void imprimeItem(TipoItem item){
  printf("%i %s\n",item.chave,item.nome);
}