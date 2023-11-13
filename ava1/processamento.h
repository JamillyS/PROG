#ifndef AVA1_PROCESSAMENTO_C
#define AVA1_PROCESSAMENTO_C

#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>




struct usuario{
    char login[10];
    char senha[10];
    char nome[30];
};

#ifdef linux
#include <unistd.h>
#elif _WIN32
#include <Windows.h>
#include <unistd.h>
#endif

void separa_usu(FILE *arquivo, struct usuario *usuario) {
    //separo os login
    fgets(usuario->login, sizeof(usuario->login), arquivo);
    //"pula" uma posição
    fgetc(arquivo);
    //separo as senhas
    fgets(usuario->senha, sizeof(usuario->senha), arquivo);
    fgetc(arquivo);
    //separo os nomes
    fgets(usuario->nome, sizeof(usuario->nome), arquivo);
    fgetc(arquivo);

    //sizeof é o responsavel por saber o tamanho se caracteres
    //coloquei um fgetc logo após o fgets pois ao debugar o fgets voltava uma pocição para trás
}


// Busca o usuario
int bucar_usu(struct usuario *usuarios, char *login, char *senha) {
    //Percorro o vetor usarios
    for (int i = 0; i < 500; i++) {

        //comparo se o login atual e passado via teclado são iguais
        if (strcmp(usuarios[i].login, login) == 0) {

            //comparo se o login atual e passado via teclado são iguais
            if (strcmp(usuarios[i].senha, senha) == 0) {
                return i;
            }
        }
    }
    // O usuário não foi encontrado
    return 0;
}
//imprimi boas vindas ao usuario
void hello(struct usuario *usuario) {
    printf("Ola, %s!Seja bem vindo.\n", usuario->nome);
}

#endif
