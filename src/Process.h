#ifndef PROCESS_H
#define PROCESS_H

//Bibliotecas
#include "Structures.h"

//Pre Processamento
#define LISTAPROCESSOS listaProcessos
//#define LISTABLOQUEADOS listaProcessosBloqueados

//Variaveis
extern ProcessBlock *listaProcessos; 
extern int quantidadeProcessos;

//Prototipos
void killProgram(int id);
void stepPrograms(ProcessBlock *inicio, int id, int linhas);
void PSPrograms(ProcessBlock *inicio);
void executePrograms(ProcessBlock *inicio, int id);
void blockCicle(ProcessBlock *inicio);

#endif