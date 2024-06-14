#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

int main(int argc, char *argv[])
{
    Node *node = NULL;   
    inserir(&node, 5);
    inserir(&node, 8);
    inserir(&node, 7);
    inserir(&node, 3);
    inserir(&node, 4);
    inserir(&node, 6);
    inserir(&node, 2);
    inserir(&node, 1);
    inserir(&node, 9);
    inserir(&node, 10);
    inserir(&node, 5);

    printf("o numero 5 esta? %d\n", buscar(node, 5));
    printf("o numero 3 esta? %d\n", buscar(node, 3));
    printf("o numero 0 esta? %d\n", buscar(node, 0));

    in_order(node);
    printf("\n");
    pre_order(node);
    printf("\n");
    post_order(node);

    remover(&node, 8);
    remover(&node, 5);
    remover(&node, 1);
    
    printf("\n");
    in_order(node);
    printf("\n");
    pre_order(node);
    printf("\n");
    post_order(node);
    return 0;
}
