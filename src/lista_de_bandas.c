#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct banda {
    char nome[21];
    char genero[21];
    int integrantes, classificacao;
} banda;

void limpar_entrada_padrao() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {};
}

void limpar_terminal() {
    system("clear || cls");
}

void preenche_bandas(banda vetor[5]) {
    printf("Adicione as suas 5 bandas favoritas.\n\n");
    for (int i = 0; i < 5; i++) {
        printf("Informe o nome da banda (máximo 20 caracteres): ");
        scanf(" %20[^\n]", vetor[i].nome);
        limpar_entrada_padrao();

        printf("Informe o gênero da banda (máximo 20 caracteres): ");
        scanf(" %20[^\n]", vetor[i].genero);
        limpar_entrada_padrao();

        printf("Informe o número de integrantes da banda: ");
        scanf(" %d", &vetor[i].integrantes);
        limpar_entrada_padrao();

        printf("Classifique a banda entre 1 e 5: ");
        scanf(" %d", &vetor[i].classificacao);
        limpar_entrada_padrao();

        printf("\n");
    }
}

void imprimir_banda(banda banda) {
    printf("Nome da banda: %s\n", banda.nome);
    printf("Gênero da banda: %s\n", banda.genero);
    printf("Total de integrantes da banda: %d\n", banda.integrantes);
    printf("Classificação: %d\n\n", banda.classificacao);
}

void imprimir_bandas(banda bandas[5]) {
    printf("Lista das suas bandas favoritas:\n\n");
    for (int i = 0; i < 5; i++) {
        imprimir_banda(bandas[i]);
    }
}

void imprimir_bandas_por_classificacao(banda bandas[5]) {
    printf("Lista das suas bandas favoritas por classificação:\n\n");

    int posicao = -1, banda_encontrada = 0;
    printf("Informe a classificação da banda: ");
    scanf(" %d", &posicao);
    limpar_entrada_padrao();
    printf("\n");

    for (int i = 0; i < 5; i++) {
        if (bandas[i].classificacao == posicao) {
            imprimir_banda(bandas[i]);
            banda_encontrada = 1;
        }
    }

    if (!banda_encontrada) {
        printf("Nenhuma banda foi encontrada.\n\n");
    }
}

void imprimir_bandas_por_genero(banda bandas[5]) {
    printf("Lista das suas bandas favoritas por gênero:\n\n");

    int banda_encontrada = 0;
    char genero[21];
    printf("Informe o gênero da banda: ");
    scanf(" %20[^\n]", genero);
    limpar_entrada_padrao();
    printf("\n");

    for (int i = 0; i < 5; i++) {
        if (strcmp(bandas[i].genero, genero) == 0) {
            imprimir_banda(bandas[i]);
            banda_encontrada = 1;
        }
    }

    if (!banda_encontrada) {
        printf("Nenhuma banda foi encontrada.\n\n");
    }
}

void verificar_banda_favorita(banda bandas[5]) {
    printf("Verificar se uma banda está na lista.\n\n");

    char nome[21];
    printf("Informe o nome da banda: ");
    scanf(" %20[^\n]", nome);
    limpar_entrada_padrao();
    printf("\n");

    for (int i = 0; i < 5; i++) {
        if (strcmp(bandas[i].nome, nome) == 0) {
            printf("A banda %s está entre as favoritas.\n\n", nome);
            return;
        }
    }

    printf("A banda %s não está entre as favoritas.\n\n", nome);
}

int menu() {
    printf(
        "Escolha um opção.\n"
        "0 - Sair.\n"
        "1 - Preencher a lista de bandas.\n"
        "2 - Exibir a lista de bandas.\n"
        "3 - Exibir a lista de bandas por classificação.\n"
        "4 - Exibir a lista de bandas por gênero.\n"
        "5 - Verificar se uma banda está na lista.\n\n");

    while (1) {
        int opcao = -1;
        printf("Opção: ");
        scanf(" %d", &opcao);
        limpar_entrada_padrao();

        if (opcao >= 0 && opcao <= 5)
            return opcao;
        else
            printf("Opção inválida.\n\n");
    }
}

int main() {
    banda bandas[5];
    int bandas_adicionadas = 0;

    int opcao;
    do {
        opcao = menu();

        if (opcao > 1 && !bandas_adicionadas) {
            limpar_terminal();
            printf(
                "Opção indisponível. "
                "Primeiro preencha a lista de bandas selecionando a opção 1.\n\n");
            continue;
        }

        limpar_terminal();
        switch (opcao) {
            case 1:
                preenche_bandas(bandas);
                bandas_adicionadas = 1;
                break;
            case 2:
                imprimir_bandas(bandas);
                break;
            case 3:
                imprimir_bandas_por_classificacao(bandas);
                break;
            case 4:
                imprimir_bandas_por_genero(bandas);
                break;
            case 5:
                verificar_banda_favorita(bandas);
                break;
        }
    } while (opcao != 0);

    printf("\nPrograma encerrado.\n\n");
    return 0;
}
