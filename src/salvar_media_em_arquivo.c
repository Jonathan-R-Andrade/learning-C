#include <stdio.h>

int main(void)
{
    char url[] = "Dados.txt";
    int numero,
        total = 0;
    float media = 0.0;
    FILE *arq;
    arq = fopen(url, "a");
    if(arq == NULL)
        puts("Problema ao abrir o arquivo!");
    else
    {
        puts("Informe numeros decimais.\n"
             "Digite 0 para parar.");
        do
        {
            printf("Numero: ");
            scanf("%d", &numero);
            fflush(stdin);
            media += numero;
            if(numero != 0)
            {
                total++;
                fprintf(arq, "%d\n", numero);
            }
        }
        while(numero != 0);
        media /= total;
        fprintf(arq, "Media = %.2f", media);
    }
    fclose(arq);
    return 0;
}
