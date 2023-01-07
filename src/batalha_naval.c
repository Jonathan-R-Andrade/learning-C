#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char tabuleiro[5][5];
int navio[3][2];
int tentativas = 0, acertos = 0;

void inicializar_tabuleiro();
void mostrar_tabuleiro();
void iniciar_navios();
void atirar();
int acertou(int linha, int coluna);
void dica(int linha_do_tiro, int coluna_do_tiro);
int verificar_local_do_tiro(int linha, int coluna);
void limpar_terminal();
void limpar_entrada_padrao();
int menu();
void jogar();

void limpar_entrada_padrao() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {};
}

int menu() {
    printf(
        "           ~~~~~~~~~~~~~~~~~~~\n"
        "           X* Batalha Naval *X\n"
        "           ~~~~~~~~~~~~~~~~~~~\n\n");

    while (1) {
        printf(
            "Escolha uma opção:\n"
            " 0 - Encerrar o jogo.\n"
            " 1 - Jogar.\n\n");

        int opcao = -1;
        printf("Opção: ");
        scanf("%d", &opcao);
        limpar_entrada_padrao();

        if (opcao == 0 || opcao == 1) {
            puts("");
            return opcao;
        } else
            printf("Opção inválida.\n\n");
    }
}

void jogar() {
    inicializar_tabuleiro();
    iniciar_navios();
    do {
        limpar_terminal();
        mostrar_tabuleiro();
        atirar();
    } while (acertos < 3);
    printf("Jogo terminado. Voce acertou os 3 navios em %d tentativas.\n\n", tentativas);
    mostrar_tabuleiro();
}

int main() {
    int opcao = menu();

    while (opcao > 0) {
        switch (opcao) {
            case 1:
                jogar();
                break;
        }
        opcao = menu();
    }

    printf("Jogo encerrado.\n");
    return 0;
}

void inicializar_tabuleiro() {
    int l, c;
    for (l = 0; l < 5; l++) {
        for (c = 0; c < 5; c++) {
            tabuleiro[l][c] = '~';
        }
    }
}

void mostrar_tabuleiro() {
    puts("    1    2    3    4    5");
    int linha, coluna;
    for (linha = 0; linha < 5; linha++) {
        printf("%d   ", (linha + 1));
        for (coluna = 0; coluna < 5; coluna++) {
            if (coluna < 4)
                printf("%c    ", tabuleiro[linha][coluna]);
            else
                printf("%c", tabuleiro[linha][coluna]);
        }
        puts("");
        coluna = 0;
    }
    puts("");
}

void iniciar_navios() {
    int i, j, linha, coluna, continuar;

    for (i = 0; i < 3; i++) {
        do {
            continuar = 0;
            srand(time(NULL));
            linha = (rand() % 5) + 1;
            coluna = (rand() % 5) + 1;
            navio[i][0] = linha;
            navio[i][1] = coluna;
            for (j = 0; j < i; j++) {
                if (navio[i][0] == navio[j][0] && navio[j][1] == navio[i][1]) continuar = 1;
            }
        } while (continuar);
    }
}

void atirar() {
    int linha, coluna, erro = 0;
    do {
        switch (erro) {
            case 1:
                printf("Esse local já foi escolhido, tente de novo.\n\n");
                break;
            case 2:
                printf("Esse local não existe, tente de novo.\n\n");
                break;
        }

        printf("Informe uma linha: ");
        scanf("%d", &linha);
        limpar_entrada_padrao();

        printf("Informe uma coluna: ");
        scanf("%d", &coluna);
        limpar_entrada_padrao();

        erro = verificar_local_do_tiro(linha, coluna);
    } while (erro);

    puts("");
    tentativas++;

    if (acertou(linha, coluna)) {
        dica(linha, coluna);
        printf("Voce acertou o tiro (%d,%d)\n\n", linha, coluna);
        tabuleiro[linha - 1][coluna - 1] = 'X';
    } else {
        dica(linha, coluna);
        tabuleiro[linha - 1][coluna - 1] = '*';
    }
}

int acertou(int linha, int coluna) {
    int i;
    for (i = 0; i < 3; i++) {
        if (navio[i][0] == linha && navio[i][1] == coluna) {
            acertos++;
            return 1;
        }
    }
    return 0;
}

void dica(int linha_do_tiro, int coluna_do_tiro) {
    int navios_na_linha = 0, navios_na_coluna = 0;
    for (int i = 0; i < 3; i++) {
        if (linha_do_tiro == navio[i][0]) navios_na_linha++;
        if (coluna_do_tiro == navio[i][1]) navios_na_coluna++;
    }

    puts("Dica:");
    printf("A linha %d tem %d navio(s)\n", linha_do_tiro, navios_na_linha);
    printf("A coluna %d tem %d navio(s)\n\n", coluna_do_tiro, navios_na_coluna);
}

int verificar_local_do_tiro(int linha, int coluna) {
    if (linha >= 1 && linha <= 5 && coluna >= 1 && coluna <= 5) {
        if (tabuleiro[linha - 1][coluna - 1] == '~')
            return 0;  // Local disponível
        else
            return 1;  // O local já foi escolhido
    }
    return 2;  // Local inexistente
}

void limpar_terminal() {
    for (int i = 0; i < 100; i++) printf("\n");
}
