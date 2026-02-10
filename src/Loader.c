//Bibliotecas
#include "Structures.h"
#include "Loader.h"
#include "Process.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//funcoes
void novoProcesso(ProcessBlock **inicio,char nomeArquivo[], char nome[]){
    ProcessBlock *novo = criarProcessBlock(quantidadeProcessos + 1,nome);
    FILE *arqPrograma = fopen(nomeArquivo,"r");
    if(arqPrograma == NULL){
        printf("\n[PROCESS] Programa nao Existente!!!!!\n\n");
    } else {
        quantidadeProcessos++;
        char linha[100], argumentotexto[100], *argumento;
        int argumentoNumerico;
        Tipo tipoargumento;
        printf("\n[LOADER] Lendo programa: %s...\n", nome);

        while(fgets(linha,100,arqPrograma) != NULL){
            
            linha[strcspn(linha,"\n")] = '\0';
            char *comando = strtok(linha," ");
            if(comando == NULL){
                continue;
            }
            
            //Comandos
            if(strcmp(comando,"malloc") == 0){
                argumento = strtok(NULL," ");
                argumentoNumerico = atoi(argumento);
                tipoargumento = NUMERICO;
            } else if(strcmp(comando,"print") == 0){
                argumento = strtok(NULL,"\0");
                strcpy(argumentotexto,argumento);
                tipoargumento = TEXTUAL;
            } else if(strcmp(comando,"wait") == 0){
                argumento = strtok(NULL," ");
                argumentoNumerico = atoi(argumento);
                tipoargumento = NUMERICO;
            } else if(strcmp(comando,"exit") == 0){
                tipoargumento = NENHUM;
            } else {
                strcpy(comando,"[PROCESS] Erro\n");
            }

            //Colocar na lista de Instrucoes
            adicionarInstruction(&(novo->inicio),comando,tipoargumento,argumentotexto,argumentoNumerico);
        }
        novo->atual = novo->inicio;
        AdicionarProcessBlock(&LISTAPROCESSOS,novo);
        printf("[LOADER] %s lido com sucesso!\n\n", nome);
    }
}