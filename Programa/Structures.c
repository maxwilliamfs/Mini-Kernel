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
NoComando* criarNoArquivo(char comando[100]){
    NoComando *novo = malloc(sizeof(NoComando));
    novo->prox = NULL;
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


