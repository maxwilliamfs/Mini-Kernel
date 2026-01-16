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
        if(strcmp(texto,"malloc") == 0 || strcmp(texto,"print" == 0)){
            
        } else if(strcmp(texto,"wait") == 0){
            
        } else if(strcmp(texto,"exit") == 0){
            
        }
    }
    
    
}