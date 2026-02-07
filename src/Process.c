//Bibliotecas
#include "Structures.h"
#include <stdio.h>
#include <string.h>
#include "Process.h"
#include "Memory.h"

//Variaveis
ProcessBlock *listaProcessos = NULL;
ProcessBlock *listaProcessosBloqueados = NULL;
int quantidadeProcessos = 0;

//Funcoes
void stepPrograms(ProcessBlock *inicio, int id, int linhas){
    ProcessBlock *atual = inicio;
    while(atual->PID != id){
        if(atual->prox == NULL){
            printf("\nERRO: Nao ha programa carregado com esse ID!!!!\n");
            return;
        }
        atual = atual->prox;
    }
    printf("\n[PROCESS] Rodando %d linhas de %s\n\n", linhas, atual->nome);
    for(int i = 0; i < linhas; i++){
        if(strcmp(atual->atual->comando,"malloc") == 0){
            if(memoryRequest(atual->atual->argumentonumerico,atual->PID)){
                printf("[MEMORY] Alocadando %d bits de memoria no sistema...\n", atual->atual->argumentonumerico);
            } else {
                printf("\n[MEMORY] Nao ha essa quantidade de memoria disponivel!!!!\n");
                printf("Fechando %s...\n", atual->nome);
                printf("\n[PROCESS] Fim do Programa %s\n", atual->nome);
                ExcluirProcessBlock(&LISTAPROCESSOS,atual->PID);
                atual->PC++;
                break;
            }
        } else if (strcmp(atual->atual->comando,"wait") == 0){
            atual->TW = atual->atual->argumentonumerico;
            atual->estado = BLOQUEADO;
            AdicionarProcessBlock(LISTABLOQUEADOS,atual);
        } else if (strcmp(atual->atual->comando,"print") == 0){
            printf("%s\n", atual->atual->argumentotextual);
        } else if (strcmp(atual->atual->comando,"exit") == 0){
            printf("Fechando %s...\n", atual->nome);
            printf("\n[PROCESS] Fim do Programa %s\n", atual->nome);
            ExcluirProcessBlock(&LISTAPROCESSOS, atual->PID);
            atual->PC++;
            break;
        } 
        atual->atual = atual->atual->prox;
        atual->PC++;
    }
    printf("\n[PROCESS] Fim do Comando (step)\n\n");
}
void executePrograms(ProcessBlock *inicio, int id){
    ProcessBlock *atual = inicio;
    while(atual->PID != id){
        if(atual->prox == NULL){
            printf("\nERRO: Nao ha programa carregado com esse ID!!!!\n");
            return;
        }
        atual = atual->prox;
    }
    printf("\n[PROCESS] Rodando %s\n\n", atual->nome);
    while(1){
        if(strcmp(atual->atual->comando,"malloc") == 0){
             if(memoryRequest(atual->atual->argumentonumerico,atual->PID)){
                printf("[%s] Alocadando %d bits de memoria no sistema...\n", atual->nome, atual->atual->argumentonumerico);
            } else {
                printf("\n[MEMORY] Nao ha essa quantidade de memoria disponivel!!!!\n");
                printf("Fechando %s...\n", atual->nome);
                printf("\n[PROCESS] Fim do Programa %s\n", atual->nome);
                ExcluirProcessBlock(&LISTAPROCESSOS,atual->PID);
                atual->PC++;
                break;
            }
        } else if (strcmp(atual->atual->comando,"wait") == 0){
            atual->TW = atual->atual->argumentonumerico;
            atual->estado = BLOQUEADO;
            AdicionarProcessBlock(LISTABLOQUEADOS,atual);
        } else if (strcmp(atual->atual->comando,"print") == 0){
            printf("%s\n", atual->atual->argumentotextual);
        } else if (strcmp(atual->atual->comando,"exit") == 0){
            printf("Fechando %s...\n", atual->nome);
            printf("\n[PROCESS] Fim do Programa %s\n", atual->nome);
            ExcluirProcessBlock(&LISTAPROCESSOS, atual->PID);
            atual->PC++;
            break;
        } 
        atual->atual = atual->atual->prox;
        atual->PC++;
    }
    printf("\n[PROCESS] Fim do Comando (step)\n\n");
}
void PSPrograms(ProcessBlock *inicio){
    ProcessBlock *atual = inicio;
    if(atual == NULL){
        printf("\nNENHUM PROGRAMA CARREGADO");
    }
    while (atual != NULL) {
        printf("\n| Processo: %s |", atual->nome);
        printf(" ID: %d |", atual->PID);
        printf(" Estado: ");
        switch (atual->estado) {
            case PRONTO:
                printf(" PRONTO |");
                break;
            case EXECUTANDO:
                printf(" EXECUTANDO |");
                break;
        }
        printf(" PC: %d |", atual->PC);
        printf(" TW: %d | ", atual->TW);
        atual = atual->prox;
    }
    printf("\n\n");
}
