#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char* argv[]){
    int i=0;

    No* H = no('A', no('B', no('C', no('D', no('E', no('F', NULL))))));

    No* L = no('X', NULL);
    lista_inserir_no_i(&H, L, 7);
    // lista_imprimir_inversa(H);
    imprimir_lista(H);
    

    exit(0);
}
