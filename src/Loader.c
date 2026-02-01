//Bibliotecas
#include "Structures.h"
#include "Loader.h"
#include "Process.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//funcoes
void novoProcesso(ProcessBlock **inicio,char nomeArquivo[100]){
    ProcessBlock *novo = criarProcessBlock(quantidadeProcessos + 1,nomeArquivo);
    quantidadeProcessos++;
    FILE *arqPrograma = fopen(nomeArquivo,"r");
    if(arqPrograma == NULL){
        printf("\nPrograma nao Existente!!!!!\n\n");
    } else {
        char linha[100], *argumento;
        int argumentoNumerico;
        while(fgets(linha,100,arqPrograma) != EOF){
            char *comando = strtok(linha," ");
            if(strcmp(comando,"malloc") == 0){
                argumento = strtok(NULL," ");
                argumentoNumerico = atoi(argumento);
                printf("%s: %d", comando,argumentoNumerico);
            }
        }
    }
}