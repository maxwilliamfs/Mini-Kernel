#include "Loader.h"
#include "Process.h"
#include "Structures.h"

//Funcoes
NoProcesso* load(char arquivo[64]){
    //Descobrindo o ID
    int id = 0;
    if(processos != NULL){
        NoProcesso *temp = processos;
        while(temp != NULL){
            id++;
            temp = temp->prox;
        }
    }
    //
    NoProcesso *novo = criarNoProcesso(arquivo, id);
    FILE *file = fopen(arquivo,"r");
    while (!EOF) {
        char texto[150];
        fgets(texto,150,file);
        char *comand[20] = strtok(texto," ");
    }
    
    
}