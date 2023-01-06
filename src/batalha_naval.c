#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char tabuleiro[5][5];
int navio[3][2];
int tiro[2];
int tentativas = 0, acertos = 0;

void inicializar_tabuleiro();
void mostrar_tabuleiro();
void iniciar_navios();
void atirar();
int acertou(int linha, int coluna);
void dica();
void alterar_tabuleiro(char pos);
int verificar_posicao();
void limpar_terminal();

int main(void) {
    int continuar = 1, c = 1;

    do {
        inicializar_tabuleiro();
        iniciar_navios();
        do {
            mostrar_tabuleiro();
            atirar();
        } while (acertos < 3);
        printf("Jogo terminado. Voce acertou os 3 navios em %d tentativas.\n\n", tentativas);
        mostrar_tabuleiro();
        do {
            puts("Deseja jogar de novo:");
            puts("0 para nao.");
            puts("1 para sim.");
            scanf("%d", &continuar);
            switch (continuar) {
                case 0:
                    c = 0;
                    break;
                case 1:
                    c = 0;
                    break;
                default:
                    printf("Opcao invalida tente de novo.\n\n");
            }
        } while (c);
    } while (continuar);
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
    int linha, coluna;
    do {
        do {
            printf("Informe uma linha: ");
            scanf("%d", &linha);
            if (linha < 1 || linha > 5) {
                printf("Por favor informe um valor entre 1 e 5\n\n");
            }
        } while (linha < 1 || linha > 5);
        do {
            printf("Informe uma coluna: ");
            scanf("%d", &coluna);
            puts("");
            if (coluna < 1 || coluna > 5) {
                printf("Por favor informe um valor entre 1 e 5\n\n");
            }
        } while (coluna < 1 || coluna > 5);
        tiro[0] = linha;
        tiro[1] = coluna;
    } while (verificar_posicao());

    tentativas++;

    if (acertou(linha, coluna)) {
        dica();
        printf("Voce acertou o tiro (%d,%d)\n\n", tiro[0], tiro[1]);
        alterar_tabuleiro('X');

    } else {
        dica();
        alterar_tabuleiro('*');
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

void alterar_tabuleiro(char pos) {
    tabuleiro[tiro[0] - 1][tiro[1] - 1] = pos;
}

void dica() {
    int linha, coluna, nl = 0, nc = 0;
    for (linha = 0; linha < 3; linha++) {
        if (tiro[0] == navio[linha][0]) nl++;
    }
    for (coluna = 0; coluna < 3; coluna++) {
        if (tiro[1] == navio[coluna][1]) nc++;
    }

    puts("Dica:");
    printf("Linha %d -> %d navio(s)\n", tiro[0], nl);
    printf("Coluna %d -> %d navio(s)\n\n", tiro[1], nc);
}

int verificar_posicao() {
    if (tabuleiro[tiro[0] - 1][tiro[1] - 1] == '~') return 0;
    puts("Posicao ocupada, tente de novo.\n");
    return 1;
}

void limpar_terminal() {
    for (int i = 0; i < 100; i++) printf("\n");
}
