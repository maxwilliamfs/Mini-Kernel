#ifndef PROCESS_H
#define PROCESS_H

//Bibliotecas
#include "Structures.h"

//Pre Processamento
#define LISTAPROCESSOS listaProcessos

//Variaveis
extern ProcessBlock *listaProcessos; 
extern int quantidadeProcessos;

//Prototipos
void stepPrograms(ProcessBlock *inicio, int linhas);
void PSPrograms(ProcessBlock *inicio);
void executePrograms(ProcessBlock *inicio);

#endif