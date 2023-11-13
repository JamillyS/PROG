#include "processamento.h"

//função que vai ler e separar os dados de login, senha e nome de cada usuario


int main(int argc, char **argv) {
    //abertura do arquivo
    FILE *arquivo;
    char arq[] = "../usuarios.dat";

    arquivo = fopen(arq, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
//----------------------------------------------------------------------------------------------------------------------
    struct usuario usuarios[500];

    //leio todos os dados do arquivo e separa no vetor usuarios
    for (int i = 0; i < 500; i++) {
        separa_usu(arquivo, &usuarios[i]);
    }

    // Lê o login e a senha do usuário
    char login[10];
    char senha[10];
    printf("Insira seu login: ");
    scanf("%s", login);
    printf("Insira sua senha: ");
    scanf("%s", senha);


    int i = bucar_usu(usuarios, login, senha);

    //se usuario nao foi encontrado(pois a contagem dos caracteres ultrapassou a contagem)
    if (i == 0){
        printf("Login ou senha invalidos.\n");
    } else {
        //usuario encontrado, chama a função de boas vindas
        hello(&usuarios[i]);
    }
    struct timeval inicio, fim;
    // Iniciando tomada de tempo
    gettimeofday(&inicio, 0);
    bucar_usu(usuarios, login, senha);
    // Finalizando tomada de tempo
    gettimeofday(&fim, 0);

    long seg = fim.tv_sec - inicio.tv_sec;
    long mseg = fim.tv_usec - inicio.tv_usec;
    double tempo_total = seg + mseg * 1e-6;

    printf("Tempo gasto: %f segundos.\n", tempo_total);

    clock_t start, end;
    double cpu_time_used;

    // Iniciando tomada de tempo
    start = clock();
    bucar_usu(usuarios, login, senha);

    // Finalizando tomada de tempo
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo gasto de CPU: %f segundos.\n", cpu_time_used);

//---------------------------------------------------------------------------------------------
    fclose(arquivo);
    return 0;
}