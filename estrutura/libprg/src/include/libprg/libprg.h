#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

typedef struct {
    double value;
    int error;
} result_t;

typedef struct {
    int *valores;
    int tam_maximo;     //quantia de inteiros
    int n_elementos;    //quantos elementos guarno no momento
} Lista;

void cria_lista(Lista *lista, int tam_maximo);

void imprime_lista(Lista *lista);

int busca_linear(Lista *lista, int x);

void inserir_nao_ordenada(Lista *lista, int x);

typedef enum { SUM, SUB } operation_t;

result_t sub(double a, double b);
result_t sum(double a, double b);
result_t compute(double a, double b, operation_t op);

#endif
