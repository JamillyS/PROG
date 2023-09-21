#include <stdio.h>
#include "libprg/libprg.h"

int main() {
    Lista minha_lista;
    cria_lista(&minha_lista,10);

    //TESTE

    minha_lista.valores[0] = 10;
    minha_lista.valores[1] = 20;
    minha_lista.valores[2] = 30;

    minha_lista.n_elementos = 3;

   imprime_lista(&minha_lista);
   printf("%d\n", busca_linear(&minha_lista, 1));

   inserir_nao_ordenada(&minha_lista, 5);
   imprime_lista(&minha_lista);
    return 0;
}
