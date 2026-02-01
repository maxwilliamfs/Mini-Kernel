#ifndef PROCESS_H
#define PROCESS_H

//Bibliotecas
#include "Structures.h"

//Variaveis
extern ProcessBlock *listaProcessos; 
extern int quantidadeProcessos;

//Prototipos
void executarProgramas(ProcessBlock **inicio);
void listarProgramas(ProcessBlock *inicio);

#endif