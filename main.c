#include <stdio.h>
#include <string.h>

int main() {

    // Definição do vetor com os produtos do supermercado
    char *lista[] = { "arroz", "feijão", "sal", "açúcar", "café", "macarrão", "milho", "leite" };

    // Cálculo do número de produtos no vetor
    int cont = sizeof(lista) / sizeof(lista[0]);

    // Loop enquanto a lista de compras não estiver vazia
    while (cont > 0) {

        // For para imprimir os produtos na lista
        for (int i = 0; i < cont; i++) {
            printf("%s, ", lista[i]);
        }

        printf("\n");

        // Pergunto para o usuário qual o produto foi adicionado ao carrinho, para depois eu remover ele do vetor
        printf("Número de produtos que faltam: %d\n", cont);

        char produto[20];
        printf("Qual item da lista você adicionou ao carrinho de compras? \n");
        scanf("%s", produto);

        // Loop que percorre o vetor
        for (int i = 0; i < cont; i++) {

            // Verifico se o produto i da lista é igual passado pelo usuário
            // strncmp usado para comparar cada produto na lista com o produto digitado pelo usuário
            if (strncmp(lista[i], produto, 20) == 0) {

                // Utilização de ponteiros para manipular o conteúdo da variável apontada
                char *aux = lista[i];
                lista[i] = lista[cont - 1];
                lista[cont - 1] = aux;

                // Loop para mover os produtos para o final da lista, eliminando o produto encontrado no passo 6.
                for (int j = i + 1; j < cont; j++) {
                    lista[j - 1] = lista[j];
                }

                cont--;
                break;
            }
        }
    }

    // Imprimo novamente o restante do produtos que estão em minha lista de compras
    for (int i = 0; i < cont; i++) {
        printf("%s, ", lista[i]);
    }

    printf("\n");
    printf("Número de produtos que faltam: %d\n", cont);

    return 0;
}
