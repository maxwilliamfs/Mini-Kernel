//Bibliotecas
#include "Memory.h"

//Variaveis globais
int Memory[TRAM][TRAM] = {0};

//Funcoes
void printmem(){
    printf("[Memory] Mapa atual da memoria:\n\n");
    for(int i = 0; i<TRAM;i++){
        for(int j = 0;j<TRAM;j++){
            printf("[%d]", Memory[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}