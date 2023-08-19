#include <stdio.h>
#include <string.h>

int main() {

    // Definição do vetor com os produtos do supermercado
    char lista[][20] = { "arroz", "feijão", "sal", "açúcar", "café", "macarrão", "milho", "leite", "carne", "frango", "manga", "maçã", "sabão" };

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

        //o for percorre o vetor lista começando na posição 0 e terminando na posição cont
        for (int i = 0; i < cont; i++) {

            //strncmp - tem a função de comparar a string dada pelo usuario com lista[i]
            //compraro o produto e lista[i] em relação aos 20 caracteres do produto na lista
            //se a o produto dado pelo usuario e a lista[i] forem iguais, devem resutar a 0
            if (strncmp(lista[i], produto, 20) == 0) {

                // Loop para mover os produtos após a posição do produto encontrado
                for (int j = i; j < cont - 1; j++) {
                    //strcpy - copia o conteudo do elemento seguinte para o elemento atual
                    strcpy(lista[j], lista[j+1]);
                }
                cont--;
                //break sai do loop if pq o produto já foi encontrado.
                break;

            }
        }
    }
//----------------------------------------------------------------------------------------------------------------------

    printf("\n");
    printf("Número de produtos que faltam: %d\n", cont);

    return 0;
}