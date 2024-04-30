#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* no(char valor, No* proximo_no){
    No* no = malloc(sizeof(No));
    no->valor = valor;
    no->proximo_no = proximo_no;
    return no;
}

void inserir_no(No* H, No* no){
    if( H != NULL){
        if( H->proximo_no == NULL){
            H->proximo_no = no;
        }
        else{
            inserir_no(H->proximo_no, no);
        }
    }
}

void imprimir_lista(No* H){
    if(H != NULL){
        printf("%c ", H->valor);
        imprimir_lista(H->proximo_no);
    }
}

int quantidade_nos(No* H){
    if( H != NULL){
        return 1 + quantidade_nos(H->proximo_no);
    }
    return 0;
}

No* copiar_lista(No* H){
   if(H != NULL){
        return no(H->valor, copiar_lista(H->proximo_no));
   }
   return NULL; 
}

void liberar_lista(No* H){
    if(H != NULL){
        liberar_lista(H->proximo_no);
        free(H);
    }
}

// atv4

int lista_verificar_existencia(No* H, char valor){
    if (H != NULL){
        if (H->valor == valor){
            return 1;
        }
        return lista_verificar_existencia(H->proximo_no, valor);
    }
    return 0;
}

int lista_verificar_ocorrencia(No* H, char valor){
    if (H != NULL){
        if (H->valor == valor){
            return 1 + lista_verificar_ocorrencia(H->proximo_no, valor);
        }
        return lista_verificar_ocorrencia(H->proximo_no, valor);
    }
    return 0;
}

void lista_imprimir_inversa(No* H){
    if(H != NULL){
        lista_imprimir_inversa(H->proximo_no);
        printf("%c ", H->valor);
    }
}

void lista_inserir_no_i(No** H, No* L, int i){
    if (quantidade_nos((*H)) >= i)
    {
        int n = 1;
        if (i == 0){
            L->proximo_no = *H;
            *H = L;
        }
        else if (i == n){
            L->proximo_no = (*H)->proximo_no;
            (*H)->proximo_no = L;
        }
        else if (i != n && i != 0){
            lista_inserir_no_i(&((*H)->proximo_no), L, i-1);
        }
    }
}
