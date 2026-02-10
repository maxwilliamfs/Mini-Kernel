//Bibliotecas
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "Structures.h"
#include "Loader.h"
#include "Memory.h"
#include "Process.h"
#include "FileSystem.h"

//Prototipos
void menuPrincipal();

//Main
int main(){
    bool repetir = true;
    while (repetir) {
        menuPrincipal();
    }
    
}

//Funcoes
void menuPrincipal(){
    //Leitura do Comando
    printf("[KERNEL] Informe um comando...\n");
    char entrada[100];
    char *comando,*argumento;
    int argumentoNumerico, argumentoNumerico2;
    fgets(entrada,100,stdin);
    if(strcmp(entrada,"\n") == 0){
        printf("\n[KERNEL] Comando invalido!\n\n");
    } else {
    entrada[strcspn(entrada,"\n")] = '\0';
    comando = strtok(entrada," ");

        //Processamento
        if(strcmp(comando,"load") == 0){
            argumento = strtok(NULL," ");
            char caminhoCompleto[100];
            sprintf(caminhoCompleto,"Programs/%s.txt",argumento);
            novoProcesso(&LISTAPROCESSOS,caminhoCompleto, argumento);
            
        } else if(strcmp(comando,"kill") == 0){
            argumento = strtok(NULL," ");
            argumentoNumerico = atoi(argumento);
            killProgram(argumentoNumerico);
        } else if(strcmp(comando,"mem") == 0){
            printMemory();
        } else if(strcmp(comando,"ps") == 0){
            PSPrograms(LISTAPROCESSOS);
        } else if(strcmp(comando,"help") == 0){
            printf("\n[KERNEL] Comandos validos:\n");
            printf("[KERNEL] <help> - Lista os comandos validos\n");
            printf("[KERNEL] <load programa> - Carrega um programa\n");
            printf("[KERNEL] <kill x> Finaliza o programa de ID x\n");
            printf("[KERNEL] <clear> Limpa o terminar KERNEL\n");
            printf("[KERNEL] <ps> - Lista os programas ja carregados\n");
            printf("[KERNEL] <step x y> -  Executa y linha do programa de ID x\n");
            printf("[KERNEL] <execute x> - Executa todas as linhas do programa de ID x\n");
            printf("[KERNEL] <mem> - Ver o uso de memorio do sistema\n");
            printf("[KERNEL] <create programa> - Cria um novo programa\n");
            printf("[KERNEL] <edit programa> - Abre a aba de edicao de codigo de um programa\n");
            printf("[KERNEL] <exit> - Fecha o sistema\n\n");
        } else if(strcmp(comando,"execute") == 0){
            argumento = strtok(NULL," ");
            argumentoNumerico = atoi(argumento);
            executePrograms(LISTAPROCESSOS,argumentoNumerico);
        } else if(strcmp(comando,"step") == 0){
            argumento = strtok(NULL," ");
            argumentoNumerico = atoi(argumento);
            argumento = strtok(NULL," ");
            argumentoNumerico2 = atoi(argumento);
            stepPrograms(LISTAPROCESSOS,argumentoNumerico,argumentoNumerico2);
        } else if(strcmp(comando,"create") == 0){
            argumento = strtok(NULL," ");
            char caminhocompleto[64];
            sprintf(caminhocompleto,"Programs/%s.txt", argumento);
            creatFile(caminhocompleto);
            printf("\n[KERNEL] Criado com sucesso!\n\n");
        } else if(strcmp(comando,"edit") == 0){
            argumento = strtok(NULL," ");
            char caminhocompleto[64];
            sprintf(caminhocompleto,"Programs/%s.txt", argumento);
            editFile(caminhocompleto);
        } else if(strcmp(comando,"exit") == 0){
            printf("[KERNEL] Fechando...");
            exit(0);
        } else if(strcmp(comando,"clear") == 0){
            system("clear");
        } else {
            printf("\n[KERNEL] Comando invalido!\n\n");
        }
    }
}