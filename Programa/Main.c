//Bibliotecas
#include "Structures.h"
#include "Loader.h"
#include "Memory.h"

//Prototipos

//Main
int main(){
    Menu();
}

//Funcoes
void Menu(){
    //Variaveis
    char op[64];
    char filenome[64];

    //Execucao
    while (1) {
        clear();
        printf("[KERNEL] Sistema Iniciado. Memoria total: %d\n", TRAM);
        printf("[KERNEL] Digite um comando (load, execute, mem, ps, kill, help).\n\n");
        scanf("%s", op);
        if(strcmp(op,"load") == 0){

        } else if (strcmp(op,"execute") == 0){

        } else if (strcmp(op,"mem") == 0){
            printmem();
        } else if (strcmp(op,"ps") == 0){
            
        } else if (strcmp(op,"kill") == 0){
            
        } else if (strcmp(op,"help") == 0){
            
        } else {
            
        }
    }
}