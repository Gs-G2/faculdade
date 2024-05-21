#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void)
{
    StackNode* top = NULL;
    push(&top, 'A');
    push(&top, 'B');
    push(&top, 'C');

    display(top);

    printf("%c ", pop(&top));
    printf("%c ", pop(&top));
    printf("%c ", pop(&top));
    printf("%c ", pop(&top));
}
