#include "LLED.h"

void LerTipoItem(TipoItem *item){
  printf("Chave: ");
  scanf("%i",&item->chave);
  getchar();
  printf("Nome: ");
  fgets(item->nome,sizeof(item->nome),stdin);
  item->nome[strlen(item->nome)-1] = '\0';
}

int main(){
  ListaLinearED lista;
  TipoItem item;
  char nome[TAM];
  int n, i, pos;

  inicializaListaLLED(&lista);
  printf("Numeros de itens a serem inseridos: ");
  scanf("%i",&n);
  for(i=0;i<n;i++){
    LerTipoItem(&item);
    if(!insereNoFinalLLED(&lista,item)){
      printf("\nErro! Não foi possível inserir!\n");
      break;
    }
  }
  //1ª função
  printf("Função - Insere na posição\n");
  printf("Posição: ");
  scanf("%d", &pos);
  LerTipoItem(&item);
  AdicionaNaPosicaoLLED(&lista, &item, pos);
  imprimeListaLLED(&lista);

  //2ª função
  printf("Função - Remove na posição\n");
  printf("Posição: ");
  scanf("%d", &pos);
  RemoveNaPosicaoLLED(&lista, pos);
  ERROlistaVaziaLLED(&lista);

  //3ª função
  printf("Função - Remove especifico\n");
  getchar();
  LerTipoItem(&item);
  RemoveEspecificoLLED(&lista, item);
  if(ERROlistaVaziaLLED(&lista)){
    destroiListaLLED(&lista);
  }
  return 0;
}