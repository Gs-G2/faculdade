/*
O seu programa deve imprimir uma mensagem de erro caso nenhum número seja informado;
Caso receba 1 ou mais números, o seu programa deverá imprimir:
A quantidade de números recebidos;
O valor médio dos números;
O menor número;
O maior número;
A lista de números em ordem crescente;
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: main int1 int2...\n");
        return -1;
    }

    int total = 0;
    double media = 0.0;
    int min;
    int arr[argc-1];

    for (int i = 1; i < argc; i++)
    {
        arr[i-1] = atoi(argv[i]);
        total += atoi(argv[i]);
    }

    media = (double)total/(argc-1);
    
    for (int i = 0; i < argc-2; i++)
    {
        min = i;
        for (int j = i+1; j < argc-1; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
    }

    printf("A quantidade de números recebidos: %d\n", argc-1);
    printf("O valor médio dos números: %.1lf\n", media);
    printf("O menor número: %d\n", arr[0]);
    printf("O maior número: %d\n", arr[argc-2]);
    printf("A lista de números em ordem crescente: ");
    for (int i = 0; i < argc-1; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int* a, int* b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
