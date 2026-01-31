#include "memory.h"
#include <stdio.h>

//variaveis
int memory[64] = {0};

//funcoes
void printMemory(){
    int k = 0;
    printf("\n[KERNEL] Gerenciamento de memoria:\n\n");
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            printf("[%d] ", memory[k++]);
        }
        printf("\n");
    }
    printf("\n");
}