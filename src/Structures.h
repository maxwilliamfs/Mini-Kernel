#ifndef STRUCTURES_H
#define STRUCTURES_H

//Enuns
typedef enum {
    PRONTO,EXECUTANDO,BLOQUEADO
} Estado;
typedef enum {
    TEXTUAL,NUMERICO,NENHUM
} Tipo;

//Structs
typedef struct Instruction {
    char comando[64];
    char argumentotextual[100];
    Tipo tipoargumento; //Enum com: Textual, Numerico, Nenhum
    int argumentonumerico;
    struct Instruction *prox;
} Instruction;
typedef struct ProcessBlock{
    int PID, PC, TW; //Process id, Program Counter, Time Wait
    char nome[64];
    Estado estado; //Enum com bloaqueado, executando, pronto.
    struct Instruction *inicio;
    struct Instruction *atual;
    struct ProcessBlock *prox;
    
} ProcessBlock;

//Prototipos
    
//ProcessBlock
ProcessBlock* criarProcessBlock(int id, char nome[64]);
void AdicionarProcessBlock(ProcessBlock **inicio,ProcessBlock *novo);
void ExcluirProcessBlock(ProcessBlock **inicio);
    
//Instruction
Instruction* criarInstuction(char comando[], Tipo tipo, char argumentoTexto[], int argumentoNumero);
void adicionarInstruction(Instruction **inicio, char comando[], Tipo tipo, char argumentoTexto[], int argumentoNumero);

#endif