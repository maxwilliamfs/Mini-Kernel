//Bibliotecas
#include "stdio.h"
#include "Structures.h"
#include "Loader.h"
#include "Memory.h"

int main(){
    while (1) {
        clear();
        printf("[KERNEL] Sistema Iniciado. Memoria total: %d\n", TRAM);
        printf("[KERNEL] Digite um comando (load, execute, mem, ps, kill).\n\n");
        break;
    }
}