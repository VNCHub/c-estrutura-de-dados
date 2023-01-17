#include "ListaEncadeada.h"

int listaVazia(TipoLista lista){
  return lista==NULL;
}

TipoLista inicializaLista(TipoLista lista){
  return NULL;
}

TipoLista destroiLista(TipoLista lista){
  TipoNoh *ptrAux1, *ptrAux2;
  if(!listaVazia(lista)){
    ptrAux1 = lista;
    ptrAux2 = ptrAux1->prox;
    while(ptrAux1->prox != NULL){
      free(ptrAux1);
      ptrAux1 = ptrAux2;
      ptrAux2 = ptrAux1->prox;
    }
    free(ptrAux1);
  }
  return NULL;
}

void imprimeItem(TipoItem item){
  printf("\t%i", item.elemento);
}

int imprimeLista(TipoLista lista, int colunaTOTAL){
  TipoNoh *ptrAux;
  int coluna = 1;
  if(!listaVazia(lista)){
    ptrAux = lista;
    while(ptrAux != NULL && coluna <= colunaTOTAL){
      if (ptrAux->item.coluna > coluna){
        printf("\t0");
      } else {
        imprimeItem(ptrAux->item);
        ptrAux = ptrAux->prox;
      }
      coluna++;
    }
    while(coluna <= colunaTOTAL){
      printf("\t0");
      coluna++;
    }
    return 1;
  }
  return 0;
}

TipoLista insereNoFinalAdaptado(TipoLista lista,TipoItem item){
  TipoNoh *novoNoh, *ptrAux;
  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  if(!listaVazia(lista)){
    ptrAux = lista;
    while(ptrAux->prox != NULL){
      ptrAux = ptrAux->prox;
    }
    ptrAux->prox = novoNoh;
  }
  else{
    lista = novoNoh;
  }
  novoNoh->item = item;
  novoNoh->prox = NULL;
  return lista;
}

TipoLista insereNoInicio(TipoLista lista,TipoItem item){
  TipoNoh *novoNoh;
  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  novoNoh->item = item;
  novoNoh->prox = lista;
  lista = novoNoh;
  return lista;
}

TipoLista removeDoFinal(TipoLista lista,TipoItem *item){
  TipoNoh *ptrAux1, *ptrAux2;
  if(!listaVazia(lista)){
    ptrAux1 = lista;
    ptrAux2 = ptrAux1->prox;
    if(ptrAux2 == NULL){
      lista = NULL;
      *item = ptrAux1->item;
      free(ptrAux1);
    }
    else{
      while(ptrAux2->prox != NULL){
        ptrAux1 = ptrAux2;
        ptrAux2 = ptrAux2->prox;
      }
      ptrAux1->prox = NULL;
      *item = ptrAux2->item;
      free(ptrAux2);
    }
    return lista;
  }
  return NULL;
}

TipoLista removeDoInicio(TipoLista lista, TipoItem *item){
  TipoNoh *ptrAux;
  if(!listaVazia(lista)){
    ptrAux = lista;
    *item = ptrAux->item;
    lista = ptrAux->prox;
    free(ptrAux);
    return lista;
  }
  return NULL;
}

TipoLista ordenaLista(TipoLista lista, int colunas){
  TipoNoh *ptraux;
  TipoItem item_temp;
  for(int i = 0; i < colunas; i++){
    ptraux = lista;
    for(int i2 = 0; i2 < colunas; i2++){
      if(ptraux != NULL){
        if(ptraux->prox != NULL){
          if(ptraux->item.coluna > ptraux->prox->item.coluna){
            item_temp = ptraux->item;
            ptraux->item = ptraux->prox->item;
            ptraux->prox->item = item_temp;
          }
        }
        ptraux = ptraux->prox;
      }
    }
  }
}

int RemoveNaPosicao(TipoLista lista, int coluna){
  TipoNoh *ptraux, *ptraux2;
  ptraux = lista;
  ptraux2 = lista;
  while(ptraux != NULL){
    if(ptraux->item.coluna == coluna){
      if (ptraux == lista){
        lista = lista->prox;
        free(ptraux);
        return 1;
      }
      ptraux2->prox = ptraux->prox;
      free(ptraux);
      return 1;
    }
    ptraux2 = ptraux;
    ptraux = ptraux->prox;
  }
  return 0;
}