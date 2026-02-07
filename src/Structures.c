#include "Structures.h"
#include <stdlib.h>
#include <string.h>
#include "Process.h"

//Funcoes
    //ProcessBlock
ProcessBlock* criarProcessBlock(int id, char nome[64]){
    ProcessBlock *novo = malloc(sizeof(ProcessBlock));
    novo->PC = 0;
    novo->PID = id;
    novo->TW = 0;
    novo->inicio = NULL;
    novo->atual = NULL;
    strcpy(novo->nome,nome);
    novo->estado = PRONTO;
    novo->prox = NULL;
    return novo;
}
void AdicionarProcessBlock(ProcessBlock **inicio,ProcessBlock *novo){
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
void ExcluirProcessBlock(ProcessBlock **inicio, int id){
    ProcessBlock *atual = (*inicio);
    if((*inicio)->PID == id){
        (*inicio) = (*inicio)->prox;
        free(atual);
    } else {
        while (atual->prox->PID != id) {
            atual = atual->prox;
        }
        ProcessBlock *excluir = atual->prox;
        atual->prox = excluir->prox;
        free(excluir);
    }
}

    //Instruction
Instruction* criarInstuction(char comando[], Tipo tipo, char argumentoTexto[], int argumentoNumero){
    Instruction *novo = malloc(sizeof(Instruction));
    strcpy(novo->comando,comando);
    novo->tipoargumento = tipo;
    if(tipo == TEXTUAL){
        strcpy(novo->argumentotextual,argumentoTexto);
    } else if(tipo == NUMERICO){
        novo->argumentonumerico = argumentoNumero;
    }
    novo->prox = NULL;
}
void adicionarInstruction(Instruction **inicio, char comando[], Tipo tipo, char argumentoTexto[], int argumentoNumero){
    Instruction *novo = criarInstuction(comando,tipo,argumentoTexto,argumentoNumero);
    if(*inicio == NULL){
        *inicio = novo;
    } else {
        Instruction *atual = *inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}