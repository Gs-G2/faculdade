#include <stdio.h>

void swap(int* a, int* b);

int main(int argc, char *argv[])
{
    int min;
    int i = 0;
    int count = 0;
    int placeholder;

    if (argc != 2) {
        printf("Usage: ./main input.txt\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Problema com o arquivo\n");
        return 2;
    }

    do
    {
        fscanf(file, "%d[^,\n]", &placeholder);
        count++;
        printf("Lendo linha %d\n", count);
    } while (!feof(file));

    fclose(file);

    int arr[count];
    file = fopen(argv[1], "r");

    do
    {
        fscanf(file, "%d[^,\n]", &arr[i]);
        i++;
    } while (!feof(file));

    for (i = 0; i < count-1; i++)
    {
        min = i;
        printf("Lendo elemento %d\n", i);
        for (int j = i+1; j < count; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
    }
    
    fclose(file);

    file = fopen("saida.txt", "w");
    for (i = 0; i < count; i++)
    {
        fprintf(file, "%d\n", arr[i]);
    }

    fclose(file);
}

void swap(int* a, int* b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 