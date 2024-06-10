#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int main(){
    QueueNode *root = NULL;
    enqueue(&root, 'A');
    enqueue(&root, 'B');
    enqueue(&root, 'C');
    enqueue(&root, 'D');

    printf("%c ", peek(root));
    printf("%c ", dequeue(&root));
    printf("%c ", peek(root));
    printf("%c ", dequeue(&root));
    printf("%c ", peek(root));
    printf("%c ", dequeue(&root));
    printf("%c ", peek(root));
    printf("%c ", dequeue(&root));
    enqueue(&root, 'A');
    display(root);
}