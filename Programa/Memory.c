//Bibliotecas
#include "Structures.h"
#include "Memory.h"

//Variaveis globais
int memory[TRAM] = {0};

//Funcoes
void printmem(){
    int limite = sqrt(TRAM);
    printf("[Memory] Mapa atual da memoria:\n\n");
    for(int i = 0,j = 0;i < TRAM; i++,j++){
        printf("[%d]", memory[i]);
        if(j == 7){
            printf("\n");
            j = -1;
        }
    }
    printf("\n");
}