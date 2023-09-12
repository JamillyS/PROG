#include <stdio.h>

//função que realiza a soma dos numeros dentro dos vetores
int soma_vector(int *vetor, int n) {
    int soma;
    for (int i = 0; i < n; i++) {
        soma = soma + vetor[i];
    }
    return soma;
    //o loop é executado n vezes, logo sua complexidade no tempo é linear (O(n)), pois é possivel observar que o tempo que o
    //algoritmo leva para responder aumenta proporcionalmente com o aumento da entrada do vetor.
}

int main() {
    
    int vector[] = {
            1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
            30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56,
            57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83,
            84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, };
    int soma = soma_vector(vector, sizeof(vector) / sizeof(int));
    printf("Elementos do vetor: %d\n", soma);
    return 0;
}