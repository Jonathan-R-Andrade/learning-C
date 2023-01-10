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

void iniciar_navios(int navio[3][2]) {
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

void inicializar_tabuleiro(char tabuleiro[5][5]) {
    int l, c;
    for (l = 0; l < 5; l++) {
        for (c = 0; c < 5; c++) {
            tabuleiro[l][c] = '~';
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

int acertou(int navio[3][2], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        if (navio[i][0] == linha && navio[i][1] == coluna) return 1;
    }
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

int dica(int navio[3][2], int linha, int coluna, int dicas[][4], int dicas_totais) {
    dicas[dicas_totais][0] = linha;
    dicas[dicas_totais][1] = 0;  // Total de navios na linha
    dicas[dicas_totais][2] = coluna;
    dicas[dicas_totais][3] = 0;  // Total de navios na coluna

    for (int i = 0; i < 3; i++) {
        if (linha == navio[i][0]) dicas[dicas_totais][1]++;
        if (coluna == navio[i][1]) dicas[dicas_totais][3]++;
    }

    return dicas_totais + 1;
}

void mostrar_dicas(int dicas[][4], int dicas_totais) {
    if (dicas_totais > 0) {
        for (int i = 0; i < dicas_totais; i++) {
            printf("Dica %d: ", i + 1);
            printf("A linha %d tem %d navio(s) | ", dicas[i][0], dicas[i][1]);
            printf("A coluna %d tem %d navio(s)\n", dicas[i][2], dicas[i][3]);
        }
        puts("");
    }
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
    int navio[3][2];
    int local_do_tiro[2];
    int dicas[3][4];
    int acertou_o_tiro = 0, acertos = 0, tentativas = 0, dicas_totais = 0;

    iniciar_navios(navio);
    inicializar_tabuleiro(tabuleiro);

    while (acertos <= 3) {
        limpar_terminal();
        mostrar_tabuleiro(tabuleiro);

        // HACK TEMPORÁRIO
        printf("HACK TEMPORÁRIO -> (%d,%d) | ", navio[0][0], navio[0][1]);
        printf("(%d,%d) | ", navio[1][0], navio[1][1]);
        printf("(%d,%d)\n\n", navio[2][0], navio[2][1]);
        // HACK TEMPORÁRIO

        if (acertou_o_tiro) {
            printf("Voce acertou o tiro (%d,%d)\n\n", local_do_tiro[0], local_do_tiro[1]);
            if (acertos == 3) break;
            dicas_totais = dica(navio, local_do_tiro[0], local_do_tiro[1], dicas, dicas_totais);
            acertou_o_tiro = 0;
        }

        mostrar_dicas(dicas, dicas_totais);

        atirar(tabuleiro, local_do_tiro);
        tentativas++;

        if (acertou(navio, local_do_tiro[0], local_do_tiro[1])) {
            acertos++;
            acertou_o_tiro = 1;
            tabuleiro[local_do_tiro[0] - 1][local_do_tiro[1] - 1] = 'X';
        } else {
            tabuleiro[local_do_tiro[0] - 1][local_do_tiro[1] - 1] = '*';
        }
    }

    imprimir_fim_de_jogo(tentativas);
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

int main() {
    int opcao = 0;
    do {
        opcao = menu();
        switch (opcao) {
            case 1:
                jogar();
                break;
        }
    } while (opcao > 0);

    printf("Jogo encerrado.\n");
    return 0;
}
