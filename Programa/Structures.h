#ifndef STRUCTURES_H
#define STRUCTURES_H

//Bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

//Structs
typedef struct NoComando
{
    char comando[100];
    struct NoArquivo *prox;
} NoComando;
typedef struct NoProcesso
{
    int id, pc;
    char nome[64];
    EstadoProcessos estado;
    struct NoArquivo *inicial;
    struct NoArquivo *atual;
    struct NoProcesso *prox;
} NoProcesso;

//Enuns
typedef enum{
    PRONTO,EXECUTANDO,BLOQUEADO,TERMINADO
} EstadoProcessos;

//Prototipos
void clear();

#endif