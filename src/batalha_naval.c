#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void limpar_terminal() {
    for (int i = 0; i < 100; i++) printf("\n");
}

void limpar_entrada_padrao() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {};
}

void iniciar_navios(int navios[3][2]) {
    int i, j, linha, coluna, continuar;
    srand(time(NULL));

    for (i = 0; i < 3; i++) {
        linha = (rand() % 5) + 1;
        coluna = (rand() % 5) + 1;
        navios[i][0] = linha;
        navios[i][1] = coluna;
        // Se a localização for repetida, subtrai 1 de i para tentar uma nova localização
        for (j = 0; j < i; j++) {
            if (navios[i][0] == navios[j][0] && navios[i][1] == navios[j][1]) {
                i--;
                break;
            };
        }
    }
}

void inicializar_tabuleiro(char tabuleiro[5][5]) {
    for (int linha = 0; linha < 5; linha++) {
        for (int coluna = 0; coluna < 5; coluna++) {
            tabuleiro[linha][coluna] = '~';
        }
    }
}

void mostrar_tabuleiro(char tabuleiro[5][5]) {
    puts("    1    2    3    4    5");
    for (int linha = 0; linha < 5; linha++) {
        printf(" %d  ", (linha + 1));
        for (int coluna = 0; coluna < 5; coluna++) {
            if (coluna < 4)
                printf("%c    ", tabuleiro[linha][coluna]);
            else
                printf("%c\n", tabuleiro[linha][coluna]);
        }
    }
    puts("");
}

int verificar_local_do_tiro(char tabuleiro[5][5], int linha, int coluna) {
    if (linha >= 1 && linha <= 5 && coluna >= 1 && coluna <= 5) {
        if (tabuleiro[linha - 1][coluna - 1] == '~')
            return 0;  // Local disponível
        else
            return 1;  // O local já foi escolhido
    }
    return 2;  // Local inexistente
}

int verificar_tiro(int navios[3][2], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        // Retorna 1 se o navio foi acertado
        if (navios[i][0] == linha && navios[i][1] == coluna) return 1;
    }
    // Retorna 0 se o navio não foi acertado
    return 0;
}

void atirar(char tabuleiro[5][5], int local_do_tiro[2]) {
    int linha = 0, coluna = 0, erro = 0;
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

        erro = verificar_local_do_tiro(tabuleiro, linha, coluna);
    } while (erro);

    local_do_tiro[0] = linha;
    local_do_tiro[1] = coluna;
}

int dar_dica(int navios[3][2], int linha, int coluna) {
    int navios_na_linha = 0;   // Total de navios na linha
    int navios_na_coluna = 0;  // Total de navios na coluna

    for (int i = 0; i < 3; i++) {
        if (linha == navios[i][0]) navios_na_linha++;
        if (coluna == navios[i][1]) navios_na_coluna++;
    }

    printf("Dica: ");
    printf("A linha %d tem %d navio(s) | ", linha, navios_na_linha);
    printf("A coluna %d tem %d navio(s)\n\n", coluna, navios_na_coluna);
}

int contar_digitos(int numero) {
    if (numero == 0) return 1;
    return (int)floor(log10(numero)) + 1;
}

void imprimir_fim_de_jogo(int tentativas) {
    int total_digitos_tentativas = contar_digitos(tentativas);
    int total_de_x = total_digitos_tentativas + 58;

    char x[total_de_x + 1];
    memset(x, 'X', total_de_x);
    x[total_de_x] = '\0';

    printf("%s\n", x);
    printf("X Fim de jogo. Você acertou os 3 navios com %d tentativas. X\n", tentativas);
    printf("%s\n\n", x);
    printf("----------------------------------------------------------------------\n\n");
}

void jogar() {
    char tabuleiro[5][5];
    int navios[3][2];      // Localização dos navios
    int local_do_tiro[2];  // Localização do último tiro dado pelo usuário
    int acertou_o_tiro = 0, acertos = 0, tentativas = 0;

    iniciar_navios(navios);
    inicializar_tabuleiro(tabuleiro);

    while (acertos <= 3) {
        limpar_terminal();
        mostrar_tabuleiro(tabuleiro);

        if (acertou_o_tiro) {
            printf("Você acertou o tiro (%d,%d)\n\n", local_do_tiro[0], local_do_tiro[1]);
            if (acertos == 3) break;
            acertou_o_tiro = 0;
        } else if (tentativas > 0) {
            dar_dica(navios, local_do_tiro[0], local_do_tiro[1]);
        }

        atirar(tabuleiro, local_do_tiro);
        acertou_o_tiro = verificar_tiro(navios, local_do_tiro[0], local_do_tiro[1]);
        tentativas++;

        if (acertou_o_tiro) {
            acertos++;
            tabuleiro[local_do_tiro[0] - 1][local_do_tiro[1] - 1] = 'X';
        } else {
            tabuleiro[local_do_tiro[0] - 1][local_do_tiro[1] - 1] = '*';
        }
    }

    imprimir_fim_de_jogo(tentativas);
}

void imprimir_como_jogar() {
    limpar_terminal();
    puts(
        "Regras:\n"
        "Em um tabuleiro 5x5, ou seja, com 25 blocos, existem 3 navios escondidos (um em cada "
        "bloco).\n"
        "Seu objetivo é atirar até acertar todos os navios.\n"
        "Se você errar o tiro, é dada uma dica informando quantos navios existem na linha e na "
        "coluna onde você atirou.\n"
        "O jogo acaba quando você acertar os três navios.\n");

    puts(
        "Legenda:\n"
        "~ - Água, nenhum tiro foi dado.\n"
        "* - Tiro dado, nenhum navio foi acertado.\n"
        "X - Tiro dado, um navio foi acertado.\n");

    puts(
        "Como jogar:\n"
        "A cada rodada você terá que dar um tiro, para isso, informe o número da linha e o número "
        "da coluna onde você quer atirar.\n"
        "Depois aguarde a mensagem dizendo que você acertou o tiro ou a dica caso você tenha "
        "errado.\n");
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
            " 1 - Jogar.\n"
            " 2 - Como jogar.\n\n");

        int opcao = -1;
        printf("Opção: ");
        scanf("%d", &opcao);
        limpar_entrada_padrao();

        if (opcao >= 0 && opcao <= 2) {
            puts("");
            return opcao;
        } else
            printf("Opção inválida.\n\n");
    }
}

int main() {
    int opcao = 0;
    do {
        opcao = menu();
        switch (opcao) {
            case 1:
                jogar();
                break;
            case 2:
                imprimir_como_jogar();
                break;
        }
    } while (opcao > 0);

    printf("Jogo encerrado.\n");
    return 0;
}
