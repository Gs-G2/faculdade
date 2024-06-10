#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "queue.h"

void enqueue(QueueNode **root, char data)
{
    QueueNode *qNode = malloc(sizeof(QueueNode));
    qNode->data = data;
    qNode->next = NULL;
    if (isEmpty(*root))
    {
        *root = qNode;
    }
    else
    {
        QueueNode *temp = (*root)->next;
        if (temp == NULL)
        {
            (*root)->next = qNode;
        }
        else
        {
            do
            {
                if (temp->next == NULL)
                {
                    temp->next = qNode;
                }
                else
                {
                    temp = temp->next;
                }

            } while (temp->next != NULL);
        }
    }
}

char dequeue(QueueNode **root)
{
    if (isEmpty(*root))
    {
        return CHAR_MIN;
    }
    else
    {
        QueueNode *temp = *root;
        *root = temp->next;
        char tempData = temp->data;
        free(temp);
        return tempData;
    }
}

char peek(QueueNode *root)
{
    if (isEmpty(root))
    {
        return CHAR_MIN;
    }
    else {
        return root->data;
    }
}

int isEmpty(QueueNode *root)
{
    return root == NULL;
}

void display(QueueNode *root) {
    QueueNode* temp = root;
    while (temp != NULL)
    {
        printf("%c <- ", temp->data);
        temp = temp->next;
    }
    
}