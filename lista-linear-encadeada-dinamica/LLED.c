#include "LLED.h"

int listaVaziaLLED(ListaLinearED *lista){
  return lista->ultimo==0;
}

int ERROlistaVaziaLLED(ListaLinearED *lista){
  if (!listaVaziaLLED(lista)){
    imprimeListaLLED(lista);
    return 1;
  }
  else{
    printf("A lista está vazia!\n");
    return 0;
  }
}

void inicializaListaLLED(ListaLinearED *lista){
  lista->inicioLista = NULL;
  lista->ultimo = 0;
}

void destroiListaLLED(ListaLinearED* lista){
  TipoNoh *ptrAux1, *ptrAux2;
  if(!listaVaziaLLED(lista)){
    ptrAux1 = lista->inicioLista;
    ptrAux2 = ptrAux1->prox;
    while(ptrAux1->prox != NULL){
      free(ptrAux1);
      ptrAux1 = ptrAux2;
      ptrAux2 = ptrAux1->prox;
    }
    free(ptrAux1);
  }
  lista->inicioLista = NULL;
  lista->ultimo = 0;
}

void imprimeItemLLED(TipoItem item){
  printf("%i %s\n",item.chave,item.nome);
}

void imprimeListaLLED(ListaLinearED *lista){
  TipoNoh *ptrAux;
  if(!listaVaziaLLED(lista)){
    ptrAux = lista->inicioLista;
    printf("----------\n");
    while(ptrAux != NULL){
      imprimeItemLLED(ptrAux->item);
      ptrAux = ptrAux->prox;
    }
    printf("----------\n");
  }
}

int insereNoFinalLLED(ListaLinearED *lista,TipoItem item){
  TipoNoh *novoNoh, *ptrAux;
  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  if(novoNoh != NULL){
    ptrAux = lista->inicioLista;
    if(!listaVaziaLLED(lista)){
      while(ptrAux->prox != NULL)
        ptrAux = ptrAux->prox;
      ptrAux->prox = novoNoh;
    }
    else{
      lista->inicioLista = novoNoh;
    }
    novoNoh->item = item;
    novoNoh->prox = NULL;
    lista->ultimo++;
    return 1;
  }
  return 0;
}

int insereNoInicioLLED(ListaLinearED *lista,TipoItem item){
  TipoNoh *novoNoh;
  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  if(novoNoh != NULL){
    novoNoh->item = item;
    novoNoh->prox = lista->inicioLista;
    lista->inicioLista = novoNoh;
    lista->ultimo++;
    return 1;
  }
  return 0;
}

int removeDoFinalLLED(ListaLinearED *lista,TipoItem *item){
  TipoNoh *ptrAux1, *ptrAux2;
  if(!listaVaziaLLED(lista)){
    ptrAux1 = lista->inicioLista;
    ptrAux2 = ptrAux1->prox;
    if(ptrAux2 == NULL){
      lista->inicioLista = NULL;
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
    lista->ultimo--;
    return 1;
  }
  return 0;
}

int removeDoInicioLLED(ListaLinearED *lista, TipoItem *item){
  TipoNoh *ptrAux;
  if(!listaVaziaLLED(lista)){
    ptrAux = lista->inicioLista;
    *item = ptrAux->item;
    lista->inicioLista = ptrAux->prox;
    free(ptrAux);
    lista->ultimo--;
    return 1;
  }
  return 0;
}

//Funções implementadas

int AdicionaNaPosicaoLLED(ListaLinearED *lista, TipoItem *item, int pos){
  TipoNoh *ptrAux, *novoNoh;
  pos = pos - 2;
  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  if(novoNoh != NULL){
    ptrAux = lista->inicioLista;
    if(!listaVaziaLLED(lista)){
      for(int i = 0; i < pos; i++){
        ptrAux = ptrAux->prox;
      }
      novoNoh->prox = ptrAux->prox;
      ptrAux->prox = novoNoh;
      novoNoh->item = *item;
    }
    else
      lista->inicioLista = novoNoh;
    lista->ultimo++;
    return 1;
    }
  else
    return 0;
}

int RemoveNaPosicaoLLED(ListaLinearED *lista, int pos){
  TipoNoh *ptrAux, *ptrAux2;
  pos = pos - 2;
  ptrAux = lista->inicioLista;
  if(!listaVaziaLLED(lista)){
    for(int i = 0; i < pos; i++){
      ptrAux = ptrAux->prox;
    }
    ptrAux2 = ptrAux->prox;
    ptrAux->prox = ptrAux->prox->prox;
    free(ptrAux2);
    lista->ultimo--;
    return 1;
  }
  else
    return 0;
}

int RemoveEspecificoLLED(ListaLinearED *lista, TipoItem item){
  TipoNoh *ptrAux, *ptrAux2;
  ptrAux = lista->inicioLista;
  if(!listaVaziaLLED(lista)){
    //testa se o item é o primeiro da lista
    if (strcmp(ptrAux->item.nome, item.nome) == 0){
      ptrAux2 = ptrAux;
      lista->inicioLista = ptrAux->prox;
      free(ptrAux2);
      lista->ultimo--;
      return 1;
    }
    else{
      //teste os demais itens da lista
      while(strcmp(ptrAux->prox->item.nome, item.nome) != 0){
        if(ptrAux->prox == NULL){
          return 0;
      }
        ptrAux = ptrAux->prox;
      }
      ptrAux2 = ptrAux->prox;
      ptrAux->prox = ptrAux->prox->prox;
      free(ptrAux2);
      lista->ultimo--;
      return 1;
    }
  }
  else
    return 0;
}