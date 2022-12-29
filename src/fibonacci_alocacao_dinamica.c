#include <stdio.h>
#include <stdlib.h>

int menu(void)
{
    int opcao;
    printf("Escolha uma opcao.\n"
           "0. Sair.\n"
           "1. Escolher um termo.\n"
           "Opcao: ");
    scanf("%d", &opcao);
    printf("\n");
    return opcao;
}

void exibe(int *ptr, int termo, int *size)
{
    if (termo > *size)
    {
        int v = (*size*sizeof(int));
        int n = ((termo-*size)*sizeof(int));
        printf("Velho %d\nNovo %d\n\n", v, n);
        ptr = (int *) realloc(ptr, v+n);
        int i;
        for(i = *size; i < termo; i++)
        {
            ptr[*size] = ptr[*size-1] + ptr[*size-2];
            *size += 1;
        }
        printf("Termo %d = %d\n\n", termo, ptr[termo-1]);
    }
    else
    {
        printf("Termo %d = %d\n\n", termo, ptr[termo-1]);
    }
}

int main(void)
{
    int opcao = 1, t, s = 2;
    int *p;
    p = (int *) malloc(2*sizeof(int));
    p[0] = 0;
    p[1] = 1;
    do
    {
        switch(menu())
        {
        case 0:
            opcao = 0;
            break;
        case 1:
            printf("Digite um termo: ");
            scanf("%d", &t);
            printf("\n");
            exibe(p, t, &s);
            break;
        default:
            printf("Opcao invalida.\n\n");
        }
    }
    while(opcao);
    return 0;
}
