#include "ABB.h"

TipoArvore instanciaArvore(int item){
    TipoArvore arvore;
    arvore = (TipoArvore)malloc(sizeof(TipoNohArvore));
    arvore->dado = item;
    arvore->SE = NULL;
    arvore->SD = NULL;
    return arvore;
}

TipoArvore insereValor(TipoArvore arvore, int item){
    if (arvore == NULL){
        arvore = instanciaArvore(item);
    }
    else if ((item - arvore->dado) < 0){
        arvore->SE = insereValor(arvore->SE, item);
    }
    else if ((arvore->dado - item) < 0){
        arvore->SD = insereValor(arvore->SD, item);
    }
    return arvore;
}

int imprimePreOrdem(TipoArvore noh, int n){
    if (noh != NULL){
        if (n){
            printf(PRINT_FORMAT, noh->dado);
            n = 0;
        }
        else{
            printf(PRINT_FORMAT_WITH_SPACE, noh->dado);
        }
        n = imprimePreOrdem(noh->SE, n);
        n = imprimePreOrdem(noh->SD, n);
    }
    return n;
}

int imprimeEmOrdem(TipoArvore noh, int n){
    if (noh != NULL){
        n = imprimeEmOrdem(noh->SE, n);
        if (n){
            printf(PRINT_FORMAT, noh->dado);
            n = 0;
        }
        else{
            printf(PRINT_FORMAT_WITH_SPACE, noh->dado);
        }
        n = imprimeEmOrdem(noh->SD, n);
    }
    return n;
}

int imprimePosOrdem(TipoArvore noh, int n){
    if (noh != NULL){
        n = imprimePosOrdem(noh->SE, n);
        n = imprimePosOrdem(noh->SD, n);
        if (n){
            printf(PRINT_FORMAT, noh->dado);
            n = 0;
        }
        else{
            printf(PRINT_FORMAT_WITH_SPACE, noh->dado);
        }
    }
    return n;
}

int pesquisaExiste(TipoArvore arvore, int item){
    int n = 0;
    if (arvore == NULL){
        return 0;
    }
    else if (arvore->dado == item){
        return 1;
    }
    else{
        n += pesquisaExiste(arvore->SE, item);
        n += pesquisaExiste(arvore->SD, item);
    }
    return n;
}

TipoArvore removeArvore(TipoArvore noh, int item){
    if(noh != NULL){
        if(noh->dado == item){
            if(noh->SE == NULL && noh->SD == NULL){
                return NULL;
            }
            if(noh->SE == NULL){    
                return noh->SD;
            } else if(noh->SD == NULL){
                return noh->SE;
            } else {
                int n;
                n = procuraMaior(noh->SE, noh->SE->dado);
                noh = removeArvore(noh->SE, n);
                noh->dado = n;
            }
        } else {
            noh->SE = removeArvore(noh->SE, item);
            noh->SD = removeArvore(noh->SD, item);
        }
    }
    return noh;
}

int procuraMaior(TipoArvore noh, int item){
    if(noh != NULL){
        if(item < noh->dado){
            item = noh->dado;
        }
        item = procuraMaior(noh->SE, item);
        item = procuraMaior(noh->SD, item);
    }
    return item;
}