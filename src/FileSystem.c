//Bibliotecas
#include "FileSystem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Funcoes
void creatFile(char nome[]){
    FILE *arq = fopen(nome,"r");
    if(arq != NULL){
        printf("\nEsse programa ja existe!!!!\n\n");
        fclose(arq);
        return;
    } 
    arq = fopen(nome,"w");
    fclose(arq);
}
void editFile(char nome[]){
    FILE *arq = fopen(nome,"r");
    if(arq == NULL){
        printf("\nEsse programa nao existe!!!!\n\n");
        return;
    } 
    fclose(arq);
    while(1){
        clear();
        printf("------- Conteudo do Arquivo -------\n\n");
        readFile(nome);
        printf("[EDITOR] Informe um comando de edicao...\n");
        char *comando, *argumento, entrada[1024];
        fgets(entrada,1024,stdin);
        entrada[strcspn(entrada,"\n")] = '\0';
        comando = strtok(entrada, " ");

        if(strcmp(comando,"write") == 0){
            argumento = strtok(NULL,"");
            writeFile(nome, argumento);
        } else if(strcmp(comando,"delete") == 0){
            deleteLine(nome);
        } else if(strcmp(comando,"exit") == 0){
            printf("\n");
            clear();
            return;
        } else if(strcmp(comando,"help") == 0){
            printf("\n[EDITOR] Comandos de edicao:\n");
            printf("[EDITOR] <help> Informa os comandos validos");
            printf("[EDITOR] <write x> Escreve x no arquivo\n");
            printf("[EDITOR] <delete x> Apaga x linhas do arquivo\n");
            printf("[EDITOR] <exit> Sai do modo edicao\n");
            printf("---------------------------------------------------------\n");
            printf("[EDITOR] Comandos para os programas:\n");
            printf("[EDITOR] <malloc x> Aloca x bits da memoria\n");
            printf("[EDITOR] <wait x> Bloqueia o programa por x cliclos do Kernel\n");
            printf("[EDITOR] <print x> Imprime x na tela\n");
            printf("[EDITOR] <exit> Fecha o programa\n");
            printf("\n[EDITOR] Pressine qualquer tecla para continuar...\n");
            getchar();
        } else {
            printf("[EDITOR] Comando invalido!!!\n");
        }
    }
}
void writeFile(char nome[], char *argumento){
    FILE *arq = fopen(nome,"a");
    fprintf(arq,"%s\n",argumento);
    fclose(arq);
}
void deleteLine(char nome[]){
    FILE *arq = fopen(nome,"r");
    FILE *arqCopia = fopen("Programs/CopiaTemporaria.txt","a");
    char atual[1024], proximo[1024];
    fgets(atual,1024,arq);
    while(fgets(proximo,1024,arq) != NULL){
        fputs(atual,arqCopia);
        strcpy(atual,proximo);
    }
    remove(nome);
    rename("Programs/CopiaTemporaria.txt",nome); 
    fclose(arq);
    fclose(arqCopia);

}
void readFile(char nome[]){
    FILE *arq = fopen(nome,"r");
    char leitura[1024];
    while (fgets(leitura,1024,arq) != NULL) {
        printf("%s", leitura);
    }   
    printf("\n");
    printf("-----------------------------------\n\n");
}
void clear(){
    system("clear");
}