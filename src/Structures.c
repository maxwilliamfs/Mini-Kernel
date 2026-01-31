#include "Structures.h"
#include <stdlib.h>
#include <string.h>
#include "Process.h"

//Funcoes
ProcessBlock* criarProcessBlock(int id, char nome[64]){
    ProcessBlock *novo = malloc(sizeof(ProcessBlock));
    novo->PC = 0;
    novo->PID = id;
    novo->TW = 0;
    novo->inicio = NULL;
    novo->atual = NULL;
    strcpy(novo->nome,nome);
    novo->inicio = PRONTO;
    novo->prox = NULL;
    return novo;
}
void AdicionarProcessBlock(ProcessBlock **inicio, int id, char nome[64]){
    ProcessBlock *novo = criarProcessBlock(id,nome);
    if((*inicio) == NULL){
        (*inicio) = novo;
    } else {
        ProcessBlock *atual = (*inicio);
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}
void ExcluirProcessBlock(ProcessBlock **inicio){
    ProcessBlock *excluir = (*inicio);
    (*inicio) = (*inicio)->prox;
    free(excluir);
}