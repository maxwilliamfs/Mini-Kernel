#include "Loader.h"
#include "Process.h"
#include "Structures.h"

//Funcoes
NoProcesso* load(char arquivo[64]){
    //Descobrindo o ID
    int id;
    if(processos == NULL){
        id = 0;
    } else {
        
    }
    //
    NoProcesso *novo = criarNoProcesso(arquivo, id);
    FILE *file = fopen(arquivo,"r");
    
}