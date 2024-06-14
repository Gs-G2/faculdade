#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

void inserir(Node **node, int data)
{
    if (*node != NULL)
    {
        if ((*node)->data == data)
        {
            printf("impossivel adiconar valores duplicados\n");
            return;
        }
        if (data > (*node)->data)
        {
            if ((*node)->right != NULL)
            {
                inserir(&(*node)->right, data);
            }
            else
            {
                Node *temp = (Node *)malloc(sizeof(Node));
                temp->data = data;
                temp->left = NULL;
                temp->right = NULL;
                (*node)->right = temp;
            }
        }
        else
        {
            if ((*node)->left != NULL)
            {
                inserir(&(*node)->left, data);
            }
            else
            {
                Node *temp = (Node *)malloc(sizeof(Node));
                temp->data = data;
                temp->left = NULL;
                temp->right = NULL;
                (*node)->left = temp;
            }
        }
    }
    else
    {
        *node = malloc(sizeof(Node));
        (*node)->data = data;
        (*node)->left = NULL;
        (*node)->right = NULL;
    }
    return;
}

void in_order(Node *node)
{
    if (node != NULL)
    {
        in_order(node->left);
        printf("%d ", node->data);
        in_order(node->right);
    }
}

void pre_order(Node *node)
{
    if (node != NULL)
    {
        printf("%d ", node->data);
        pre_order(node->left);
        pre_order(node->right);
    }
}

void post_order(Node *node)
{
    if (node != NULL)
    {
        post_order(node->left);
        post_order(node->right);
        printf("%d ", node->data);
    }
}

int buscar(Node *node, int data)
{
    if (node != NULL)
    {
        if (node->data == data)
        {
            return 1;
        }
        else if (node->data < data)
        {
            buscar(node->right, data);
        }
        else if (node->data > data)
        {
            buscar(node->left, data);
        }
    }
    else
    {
        return 0;
    }
}

void remover(Node **node, int data)
{
    if (*node == NULL)
    {
        return;
    }

    if ((*node)->data < data)
    {
        remover(&(*node)->right, data);
    }
    else if ((*node)->data > data)
    {
        remover(&(*node)->left, data);
    }
    else
    {
        Node *temp;
        if ((*node)->left == NULL)
        {
            temp = *node;
            *node = (*node)->right;
            free(temp);
        }
        else if ((*node)->right == NULL)
        {
            temp = *node;
            *node = (*node)->left;
            free(temp);
        }
        else
        {
            temp = (*node)->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            (*node)->data = temp->data;
            remover(&(*node)->right, temp->data);
        }
    }
}
