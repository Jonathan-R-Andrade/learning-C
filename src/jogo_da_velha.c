#include <stdio.h>
#include <string.h>

void exibir_tabuleiro(char tabuleiro[][3]) {
    printf(
        "\n        1   2   3\n\n"
        "   1    %c | %c | %c\n"
        "       ---|---|---\n"
        "   2    %c | %c | %c\n"
        "       ---|---|---\n"
        "   3    %c | %c | %c\n\n",
        tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2], tabuleiro[1][0], tabuleiro[1][1],
        tabuleiro[1][2], tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
}

void limpar_terminal() {
    for (int i = 0; i < 100; i++) printf("\n");
}

void limpar_entrada_padrao() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {};
}

void imprimir_vencedor(char *nome_do_jogador) {
    int tamanho_nome_jogador = (int)strlen(nome_do_jogador);
    int tamanho_texto_vencedor = 27;
    int total_de_asteriscos = tamanho_nome_jogador + tamanho_texto_vencedor;

    char asteriscos[total_de_asteriscos + 1];
    memset(asteriscos, '*', total_de_asteriscos);
    asteriscos[total_de_asteriscos] = '\0';

    printf("%s\n", asteriscos);
    printf("* PARABÉNS %s, VOCÊ VENCEU! *\n", nome_do_jogador);
    printf("%s\n\n", asteriscos);
    printf("-------------------------------------------------------\n\n");
}

int verificar_posicao(char tabuleiro[][3], int linha, int coluna) {
    if (linha >= 0 && linha <= 2 && coluna >= 0 && coluna <= 2) {
        if (tabuleiro[linha][coluna] == ' ')
            return 0;  // Posição disponível
        else
            return 1;  // A posição já foi escolhida
    }
    return 2;  // Posição inexistente
}

void solicitar_posicao(char tabuleiro[][3], int indice_do_jogador, char *nome_do_jogador) {
    int linha = 0, coluna = 0, erro = 0;
    char simbolo_do_jogador;

    if (indice_do_jogador == 0)
        simbolo_do_jogador = 'X';
    else
        simbolo_do_jogador = 'O';

    do {
        limpar_terminal();
        exibir_tabuleiro(tabuleiro);
        printf("-> Sua vez %s, seu símbolo é %c.\n\n", nome_do_jogador, simbolo_do_jogador);

        switch (erro) {
            case 1:
                printf("Essa posição já foi escolhida, tente de novo.\n\n");
                break;
            case 2:
                printf("Essa posição não existe, tente de novo.\n\n");
                break;
        }

        printf("Informe uma linha: ");
        scanf("%d", &linha);
        limpar_entrada_padrao();

        printf("Informe uma coluna: ");
        scanf("%d", &coluna);
        limpar_entrada_padrao();

        linha--;
        coluna--;
        erro = verificar_posicao(tabuleiro, linha, coluna);
    } while (erro);

    tabuleiro[linha][coluna] = simbolo_do_jogador;
}

int verificar_linha(char tabuleiro[][3]) {
    int indice_do_vencedor = -1;

    for (int linha = 0; linha < 3; linha++) {
        if (tabuleiro[linha][0] == tabuleiro[linha][1] &&
            tabuleiro[linha][1] == tabuleiro[linha][2]) {
            if (tabuleiro[linha][0] == 'X') indice_do_vencedor = 0;
            if (tabuleiro[linha][0] == 'O') indice_do_vencedor = 1;
        }
    }

    return indice_do_vencedor;
}

int verificar_coluna(char tabuleiro[][3]) {
    int indice_do_vencedor = -1;

    for (int coluna = 0; coluna < 3; coluna++) {
        if (tabuleiro[0][coluna] == tabuleiro[1][coluna] &&
            tabuleiro[1][coluna] == tabuleiro[2][coluna]) {
            if (tabuleiro[0][coluna] == 'X') indice_do_vencedor = 0;
            if (tabuleiro[0][coluna] == 'O') indice_do_vencedor = 1;
        }
    }

    return indice_do_vencedor;
}

int verificar_diagonal(char tabuleiro[][3]) {
    int indice_do_vencedor = -1;

    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) {
        if (tabuleiro[0][0] == 'X') indice_do_vencedor = 0;
        if (tabuleiro[0][0] == 'O') indice_do_vencedor = 1;
    } else if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) {
        if (tabuleiro[0][2] == 'X') indice_do_vencedor = 0;
        if (tabuleiro[0][2] == 'O') indice_do_vencedor = 1;
    }

    return indice_do_vencedor;
}

int verificar_vencedor(char tabuleiro[][3]) {
    int indice_do_vencedor = verificar_linha(tabuleiro);
    if (indice_do_vencedor != -1) return indice_do_vencedor;

    indice_do_vencedor = verificar_coluna(tabuleiro);
    if (indice_do_vencedor != -1) return indice_do_vencedor;

    return verificar_diagonal(tabuleiro);
}

void iniciar_partida(char nomes_dos_jogadores[2][21]) {
    char tabuleiro[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '},
    };

    int indice_do_vencedor = -1;

    for (int i = 0; i < 9; i++) {
        int indice_do_jogador = i % 2;
        char *nome_do_jogador = nomes_dos_jogadores[indice_do_jogador];

        solicitar_posicao(tabuleiro, indice_do_jogador, nome_do_jogador);

        indice_do_vencedor = verificar_vencedor(tabuleiro);

        if (indice_do_vencedor != -1) break;
    }

    limpar_terminal();
    exibir_tabuleiro(tabuleiro);

    if (indice_do_vencedor != -1) {
        char *nome_do_jogador = nomes_dos_jogadores[indice_do_vencedor];
        imprimir_vencedor(nome_do_jogador);
    } else {
        printf(
            "**********\n"
            "* EMPATE *\n"
            "**********\n\n"
            "-------------------------------------------------------\n\n");
    }
}

int menu() {
    printf(
        "           #################\n"
        "           # Jogo da Velha #\n"
        "           #################\n\n");

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

void pegar_nome_do_jogador(int indice_do_jogador, char nomes_dos_jogadores[2][21]) {
    char *nome_do_jogador = nomes_dos_jogadores[indice_do_jogador];
    while (1) {
        printf("Informe o nome do jogador %d: ", indice_do_jogador + 1);
        scanf(" %20[^\n]", nome_do_jogador);
        limpar_entrada_padrao();
        puts("");

        int tamanho_do_nome = (int)strlen(nome_do_jogador);

        if (tamanho_do_nome > 2)
            break;
        else
            puts("O nome do jogador deve ter no mínimo três caracteres.\n");
    }
}

int main() {
    char nomes_dos_jogadores[2][21];
    int opcao = menu();

    if (opcao == 1) {
        pegar_nome_do_jogador(0, nomes_dos_jogadores);
        pegar_nome_do_jogador(1, nomes_dos_jogadores);
    }

    while (opcao == 1) {
        iniciar_partida(nomes_dos_jogadores);
        opcao = menu();
    }

    printf("Jogo encerrado.\n");
    return 0;
}
