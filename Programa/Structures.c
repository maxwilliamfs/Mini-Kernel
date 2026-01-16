#include "Structures.h"

//Funcoes Gerais
void clear(){
    #ifdef _WIN32
        system("cls");    
    #else
        system("clear");
    #endif
}

//Funcoes Comando
NoComando* criarNoComando(char comando[20], char argutexto[100], int arguint){
    NoComando *novo = malloc(sizeof(NoComando));
    novo->prox = NULL;
    novo->argumentonumerico = arguint;
    strcpy(novo->argumentotexto,argutexto);
    strcpy(novo->comando,comando);
    return novo;
}

//Funcoes Processos
NoProcesso* criarNoProcesso(char nome[64], int id){
    NoProcesso *novo = malloc(sizeof(NoProcesso));
    novo->prox = NULL;
    novo->pc = 0;
    novo->estado = PRONTO;
    novo->inicial = NULL;
    novo->atual = NULL;
    strcpy(novo->nome,nome);
    return novo;
}


