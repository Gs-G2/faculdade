#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

void push(StackNode** root, char data){
    StackNode* stackNode = malloc(sizeof(StackNode));
    stackNode->data = data;
    stackNode->next = *root;
    *root = stackNode;
}

char pop(StackNode** root){
    if (isEmpty(*root)) {
        return CHAR_MIN;
    }
    StackNode* temp = *root;
    *root = temp->next;
    char tempData = temp->data;
    free(temp);
    return tempData;
}

char peek(StackNode* root){
    if (isEmpty(root)) {
        return CHAR_MIN;
    }
    return root->data;
}

int isEmpty(StackNode* root){
    return root == NULL;
}

void display(StackNode* root){
    StackNode* temp = root;
    while (temp != NULL)
    {
        printf("%c -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}