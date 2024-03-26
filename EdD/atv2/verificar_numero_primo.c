#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int num = atoi(argv[1]);
    if (argc < 2)
    {
        printf("Uso: verificar_numero_primo num");
    }

    if (num <= 1)
    {
        printf("false");
        return -1;
    }

    for (int i = 2; i < atoi(argv[1]); i++)
    {
        if (num % i == 0)
        {
            printf("false");
            return -1;
        }
    }
    printf("true");
    return 0;
}