//Bibliotecas
#include "Structures.h"
#include <stdio.h>
#include <string.h>
#include "Process.h"
#include "Memory.h"

//Variaveis
ProcessBlock *listaProcessos = NULL;
int quantidadeProcessos = 0;

//Funcoes
void stepPrograms(ProcessBlock *inicio, int linhas){
    printf("\n[PROCESS] Rodando %d linhas de %s\n\n", linhas, inicio->nome);
    for(int i = 0; i < linhas; i++){
        if(strcmp(inicio->atual->comando,"malloc") == 0){
            if(memoryRequest(inicio->atual->argumentonumerico,inicio->PID)){
                printf("[MEMORY] Alocadando %d bits de memoria no sistema...\n", inicio->atual->argumentonumerico);
            } else {
                printf("Nao ha essa quantidade de memoria disponivel!!!!");
            }
        } else if (strcmp(inicio->atual->comando,"wait") == 0){
            printf("ainda nao sei oq fzr\n");
        } else if (strcmp(inicio->atual->comando,"print") == 0){
            printf("%s\n", inicio->atual->argumentotextual);
        } else if (strcmp(inicio->atual->comando,"exit") == 0){
            printf("Fechando %s...\n", inicio->nome);
            printf("\n[PROCESS] Fim do Programa %s\n", inicio->nome);
            ExcluirProcessBlock(&LISTAPROCESSOS);
            inicio->PC++;
            break;
        } 
        inicio->atual = inicio->atual->prox;
        inicio->PC++;
    }
    printf("\n[PROCESS] Fim do Comando (step)\n\n");
}
void executePrograms(ProcessBlock *inicio){
    printf("\n[PROCESS] Rodando %s\n\n", inicio->nome);
    while(1){
        if(strcmp(inicio->atual->comando,"malloc") == 0){
             if(memoryRequest(inicio->atual->argumentonumerico,inicio->PID)){
                printf("[MEMORY] Alocadando %d bits de memoria no sistema...\n", inicio->atual->argumentonumerico);
            } else {
                printf("Nao ha essa quantidade de memoria disponivel!!!!");
            }
        } else if (strcmp(inicio->atual->comando,"wait") == 0){
            printf("ainda nao sei oq fzr\n");
        } else if (strcmp(inicio->atual->comando,"print") == 0){
            printf("%s\n", inicio->atual->argumentotextual);
        } else if (strcmp(inicio->atual->comando,"exit") == 0){
            printf("Fechando %s...\n", inicio->nome);
            printf("\n[PROCESS] Fim do Programa %s\n", inicio->nome);
            ExcluirProcessBlock(&LISTAPROCESSOS);
            inicio->PC++;
            break;
        } 
        inicio->atual = inicio->atual->prox;
        inicio->PC++;
    }
    printf("\n[PROCESS] Fim do Comando (step)\n\n");
}
void PSPrograms(ProcessBlock *inicio){
    ProcessBlock *atual = inicio;
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
