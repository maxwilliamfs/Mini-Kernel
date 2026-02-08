#include "Structures.h"
#include "Memory.h"
#include <stdbool.h>
#include <stdio.h>


//variaveis
int memory[MEM] = {0};

//funcoes
void cleanMemory(ProcessBlock *atual){
    for(int i = 0; i < MEM; i++){
        if(memory[i] == atual->PID){
            memory[i] = 0;
        }
    }
}
void printMemory(){
    int k = 0;
    printf("\n[MEMORY] Gerenciamento de memoria:\n\n");
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            printf("[%d] ", memory[k++]);
        }
        printf("\n");
    }
    printf("\n");
}
bool memoryRequest(int quantidade, int id){
    for(int i = 0; i<MEM; i++){
        bool flag = false;
        if(memory[i] == 0){
            flag = true;
            for(int j = i; (j-i) < quantidade;j++){
                if(i + quantidade > MEM){
                    return false;
                }
                if(memory[j] != 0){
                    flag = false;
                }
            }
        }
        if(flag){
            int inicio = i;
            for(int k = inicio; (k-inicio) < quantidade; k++){
                memory[k] = id;
            }
            return true;
        }
    }
    return false;
}