#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: ./main input.txt\n");
        return 1;
    }

    if (argc == 0)
    {
        printf("Arquivo deve ser do tipo csv");
        return 3; 
    }
    double somatorio1 = 0;
    double somatorio2 = 0;
    double media_x = 0;
    double media_y = 0;
    int count = 0;
    double placeholder;
    double placeholder2;
    char dump;
    double x;
    double y;
    double inclinacao = 0;
    double interceptacao = 0;

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Problema com o arquivo\n");
        return 2;
    }

    while (fscanf(file, "%lf%c%lf", &placeholder, &dump, &placeholder2) != EOF)
    {
        count++;
    }
    fclose(file);

    double arrx[count];
    double arry[count];  
    int index = 0;

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Problema com o arquivo\n");
        return 2;
    }
    while (fscanf(file, "%lf%c%lf", &x, &dump, &y) != EOF)
    {
        arrx[index] = x;
        arry[index] = y;
        media_x += x;
        media_y += y;
        index++;
    }
    media_x = media_x / count;
    media_y = media_y / count;
    
    for (int i = 0; i < count; i++){
        somatorio1 += ((arrx[i]-media_x) * (arry[i] - media_y));
        somatorio2 += ((arrx[i]-media_x) * (arrx[i] - media_x));
    }
    inclinacao = somatorio1 / somatorio2;
    interceptacao = media_y - (inclinacao * media_x);

    printf("y = %.1lfx + %.0lf", inclinacao, interceptacao);

}