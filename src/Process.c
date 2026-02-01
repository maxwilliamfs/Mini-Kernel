//Bibliotecas
#include "Structures.h"
#include <stdio.h>

//Variaveis
ProcessBlock *listaProcessos = NULL;
extern int quantidadeProcessos = 0;

//Funcoes
void executarProgramas(ProcessBlock **inicio){

}
void listarProgramas(ProcessBlock *inicio){
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
