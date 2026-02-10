//Bibliotecas
#include "FileSystem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Funcoes
void creatFile(char nome[64]){
    FILE *arq = fopen(nome,"r");
    if(arq != NULL){
        printf("\nEsse programa ja existe!!!!\n\n");
        fclose(arq);
        return;
    } 
    arq = fopen(nome,"w");
    fclose(arq);
}
void editFile(char nome[64]){
    FILE *arq = fopen(nome,"r");
    if(arq == NULL){
        printf("\nEsse programa nao existe!!!!\n\n");
        return;
    } 
    fclose(arq);
    while(1){
        clear();
        printf("------------------------------------- MODO EDICAO ----------------------------------------------\n\n");
        printf("------- Conteudo do Arquivo -------\n\n");
        readFile(nome);
        printf("Informe um comando de edicao...\n");
        char *comando, *argumento, entrada[100];
        fgets(entrada,100,stdin);
        entrada[strspn(entrada,"\n")] = '\0';
        comando = strtok(entrada, " ");

        if(strcmp(comando,"write") == 0){
            writeFile(nome);
        } else if(strcmp(comando,"delete") == 0){
            
        } else if(strcmp(comando,"exit") == 0){
            
        } else if(strcmp(comando,"help") == 0){
            printf("\n<help> Informa os comandos validos");
            printf("<write x> Escreve a linha x no arquivo");
            printf("<delete x> Apaga x linhas do arquivo");
            printf("<exit> Sai do modo edicao\n\n");
        } else {
            printf("Comando invalido!!!\n");
        }
    }
}
void writeFile(char nome[64]){

}
void readFile(char nome[64]){
    FILE *arq = fopen(nome,"r");
    char leitura[100];
    while (fgets(leitura,100,arq) != NULL) {
        printf("%s", leitura);
    }   
    printf("\n");
    printf("-----------------------------------\n\n");
}
void clear(){
    system("clear");
}