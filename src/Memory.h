#ifndef MEMORY_H
#define MEMORY_H

//Bibliotecas
#include <stdbool.h>

//PreProcessamento
#define MEM 64

//Variaveis
extern int memory[MEM];

//Prototipos
void cleanMemory(ProcessBlock *atual);
void printMemory();
bool memoryRequest(int quantidade, int id);
#endif