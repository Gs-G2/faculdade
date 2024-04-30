#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

int main(int argc, char* argv[]){

    No* H = no('A', NULL);
    inserir_no(H, 'B');
    inserir_no(H, 'C');

    imprimir_lista(H);
    printf("\n");

    printf("\n");
    liberar_lista(H);
    imprimir_lista(H);

    exit(0);
}