#ifndef AVA1_PROCESSAMENTO_C
#define AVA1_PROCESSAMENTO_C

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>


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


#endif
