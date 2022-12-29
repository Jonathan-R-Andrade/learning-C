#include <stdio.h>
#include <string.h>

typedef struct banda
{
    char nome[30];
    char genero[15];
    int integrantes, classificacao;
} banda;

void preenche(banda vetor[])
{
    int i;
    for (i = 0; i < 5; i++)
    {
        fflush(stdin);
        printf("Informe o nome da banda: ");
        gets(vetor[i].nome);
        printf("Informe o genero da banda: ");
        gets(vetor[i].genero);
        printf("Informe o numero de integrantes da banda: ");
        scanf(" %d", &vetor[i].integrantes);
        printf("Em qual posicao essa banda esta entre 1 e 5: ");
        scanf(" %d", &vetor[i].classificacao);
        printf("\n");
    }
}

void exibe(banda *vetor)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("Nome da banda: %s\n", vetor[i].nome);
        printf("Genero da banda: %s\n", vetor[i].genero);
        printf("Total de integrantes da banda: %d\n", vetor[i].integrantes);
        printf("Classificacao: %d\n\n", vetor[i].classificacao);
    }
}

void exibec(banda vetor[])
{
    int i, posicao;
    printf("Informe a posicao da banda: ");
    scanf("%d", &posicao);
    printf("\n");
    for (i = 0; i < 5; i++)
    {
        if(vetor[i].classificacao == posicao)
        {
            printf("Nome da banda: %s\n", vetor[i].nome);
            printf("Genero da banda: %s\n", vetor[i].genero);
            printf("Total de integrantes da banda: %d\n", vetor[i].integrantes);
            printf("Classificacao: %d\n\n", vetor[i].classificacao);
        }
    }
}

void exibeg(banda vetor[])
{
    int i;
    char genero[15];
    printf("Informe o genero da banda: ");
    fflush(stdin);
    gets(genero);
    printf("\n");
    for (i = 0; i < 5; i++)
    {
        if(strcmp(vetor[i].genero, genero) == 0)
        {
            printf("Nome da banda: %s\n", vetor[i].nome);
            printf("Genero da banda: %s\n", vetor[i].genero);
            printf("Total de integrantes da banda: %d\n", vetor[i].integrantes);
            printf("Classificacao: %d\n\n", vetor[i].classificacao);
        }
    }
}

void favorita(banda vetor[])
{
    int i, b = 0;
    char nome[20];
    printf("Informe o nome de uma banda: ");
    fflush(stdin);
    gets(nome);
    printf("\n");
    for (i = 0; i < 5; i++)
    {
        if(strcmp(vetor[i].nome, nome) == 0)
        {
            printf("A banda %s esta entre as minhas favoritas.\n\n", nome);
            b = 1;
        }
    }
    if(b == 0)
    {
        printf("A banda %s nao esta entre as minhas favoritas.\n\n", nome);
    }
}

void menu(banda vetor[])
{
    int opcao;
    do
    {
        printf("        Escolha um opcao.\n"
               "0 para sair.\n"
               "1 para preencher a lista de bandas.\n"
               "2 para exibir a lista de bandas.\n"
               "3 para exibir uma banda por classificacao.\n"
               "4 para exibir uma banda por genero.\n"
               "5 para saber se uma banda e favorita.\n"
               "Opcao: ");
        scanf("%d", &opcao);
        printf("\n");
        switch(opcao)
        {
        case 0:
            break;
        case 1:
            preenche(vetor);
            break;
        case 2:
            exibe(vetor);
            break;
        case 3:
            exibec(vetor);
            break;
        case 4:
            exibeg(vetor);
            break;
        case 5:
            favorita(vetor);
            break;
        default:
            system("clear || cls");
            printf("Por favor informe uma opcao valida.\n\n");
        }
    }
    while(opcao);
}

int main(void)
{
    banda vetor[2];
    menu(vetor);
    return 0;
}
