#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

//A função garante que o pai seja maior ou igual a seus filhos.
void alcacao_correta(int *vetor, int n, int i) {
    int maior = i; //é inicializado com o valor de i
    //O índice do filho esquerdo do nó é o dobro do índice do pai, mais 1.
    //filho esquerdo é o primeiro filho do pai.
    int valores_esquerda = 2 * i + 1;
    //filho direiro é o segundo filho do pai.
    int valores_direita = 2 * i + 2;

    //se valores_esquerda é menor que o vetor e valores_esquerda é maior que "maior"
    if (valores_esquerda < n && vetor[valores_esquerda] > vetor[maior]) {
        //atualiza o valor valores_esquerda
        maior = valores_esquerda;
    }
    //se valores_direita é menor que o vetor e valores_direita é maior que "maior"
    if (valores_direita < n && vetor[valores_direita] > vetor[maior]) {
        //atualiza o valor valores_direita
        maior = valores_direita;
    }
    // se maior != i, o indice é trocado
    if (maior != i) {
        int temp = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = temp;
        //chama alcacao_correta, com o indice maior como argumento
        alcacao_correta(vetor, n, maior);
    }
}

//a função chama os valores do vetor e começa no indice (n/2) - 1 é decrementando até o índice 0,
// para alcançar o ultimo pai da arvore binaria
void construir_heap(int *vetor, int n) {
    for (int i = (n/2) - 1; i >= 0; i--) {
        alcacao_correta(vetor, n, i);
    }
}

// move o maior elemento do vetor para a posição final
void mover_elemento(int *vetor, int n) {
    //aux tem o mesmo tamanho do vetor original.
    int *aux = malloc(n * sizeof(int));
    //até o vetor ficar vazio
    for (int i = 0; i < n; i++) {
        aux[i] = vetor[i];
    }
    //chama a função construir_heap para construir um heap no vetor auxiliar.
    construir_heap(aux, n);

    //move o maior elemento do vetor auxiliar para o índice atual do vetor original.
    for (int i = n - 1; i >= 0; i--) {
        vetor[i] = aux[0];
        aux[0] = aux[i];
        //chama a função alcacao_correta para realizar a alocação correta
        alcacao_correta(aux, i, 0);
    }
    //libera a memoria que foi reservada para aux
    free(aux);
}

int main() {
    FILE *arquivo;
    arquivo = fopen("../8.txt", "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int tamanhoMaximo = 1000000000; // Defina o tamanho máximo do vetor
    int *vetor = (int *)malloc(tamanhoMaximo * sizeof(int));
    int n = 0; // Tamanho real do vetor
    char linha[100]; // Tamanho máximo de uma linha no arquivo

    if (vetor == NULL) {
        perror("Erro ao alocar memória para o vetor");
        return 1;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        int numero = atoi(linha); // Converte a linha para inteiro

        if (n < tamanhoMaximo) {
            vetor[n] = numero; // Armazena o inteiro no vetor
            n++;
        } else {
            printf("O vetor está cheio. Aumente o tamanho máximo.\n");
            break;
        }
    }

    fclose(arquivo);

    //tempo cpu
    clock_t start, end;
    double cpu_time_used;

    //tempo relogio fisico
    struct timeval inicio, fim;

    //tempo cpu
    start = clock();

    //tempo relogio físico
    gettimeofday(&inicio, 0);

    mover_elemento(vetor, n);

    //tempo cpu
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo gasto de CPU: %f segundos.\n", cpu_time_used);

    //tempo relogio físico
    gettimeofday(&fim, 0);
    long seg = fim.tv_sec - inicio.tv_sec;
    long mseg = fim.tv_usec - inicio.tv_usec;
    double tempo_total = seg + mseg * 1e-6;

    printf("Tempo gasto: %f segundos.\n", tempo_total);
//caso queira
//imprimi o heap
//    for (int i = 0; i < n; i++) {
//        printf("%d ", vetor[i]);
//    }

    printf("\n");

    free(vetor);

    return 0;
}