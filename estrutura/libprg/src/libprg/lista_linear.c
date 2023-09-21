#include "libprg/libprg.h"
#include "stdlib.h"
#include "stdio.h"

void cria_lista(Lista *lista, int tam_maximo){
    lista -> valores = malloc((sizeof (int))* tam_maximo); // sizeof da o tamanho de um tipo
    if (lista -> valores == NULL){
        printf("Falha na alocação de memoria\n");
        exit(1);
    }
    lista -> tam_maximo = tam_maximo;
    lista -> n_elementos = 0;
}

void imprime_lista(Lista *lista){
    for (int i = 0; i < lista->n_elementos; i++) {
        printf(" %d", lista->valores[i]);
    }
}

int busca_linear(Lista *lista, int x){
    for (int i = 0; i < lista->n_elementos; i++ ){
        if (x == lista->valores[i]){
            printf("\no valor está na lista ");
            return 1;
        }
        printf("\no valor não está na lista ");
        return 0;
    }
    //retorna 1 se o elemento x pertence a lista
    // ou 0, caso contrario.
}

void inserir_nao_ordenada(Lista *lista, int x){
    for (int i = 0; i < lista->n_elementos; i++ ){
        if (x == lista->valores[i]){
            printf("pertence a lista");
        }
    }
    //falta volocar aqui alguma coisa
}

//remover

