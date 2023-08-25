#include "processamento.c"

//função que vai ler e separar os dados de login, senha e nome de cada usuario
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
    printf("Ola, %s! Seja bem vindo.\n", usuario->nome);
}

int main() {
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

    //buco o usuario
    int i = bucar_usu(usuarios, login, senha);

    //se usuario nao foi encontrado(pois a contagem dos caracteres ultrapassou a contagem)
    if (i == -1) {
        printf("Login ou senha invalidos.\n");
    } else {
        //usuario encontrado, chama a função de boas vindas
        hello(&usuarios[i]);
    }
    fclose(arquivo);
    return 0;
}
