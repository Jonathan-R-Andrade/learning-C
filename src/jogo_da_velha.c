#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char nomes_dos_jogadores[2][21];

void exibir_tabuleiro(char tabuleiro[][3])
{
    printf("\n        1   2   3\n\n"
           "   1    %c | %c | %c\n"
           "       ---|---|---\n"
           "   2    %c | %c | %c\n"
           "       ---|---|---\n"
           "   3    %c | %c | %c\n\n",
           tabuleiro[0][0],
           tabuleiro[0][1],
           tabuleiro[0][2],
           tabuleiro[1][0],
           tabuleiro[1][1],
           tabuleiro[1][2],
           tabuleiro[2][0],
           tabuleiro[2][1],
           tabuleiro[2][2]);
}

void limpar_terminal()
{
    for (int i = 0; i < 100; i++)
        printf("\n");
}

void limpar_entrada_padrao()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    };
}

void imprimir_vencedor(int indice_do_jogador)
{
    char *nome_do_jogador = nomes_dos_jogadores[indice_do_jogador];
    int tamanho_nome_jogador = (int)strlen(nome_do_jogador);
    int tamanho_texto_vencedor = 27;
    int total_de_asteriscos = tamanho_nome_jogador + tamanho_texto_vencedor;

    char asteriscos[total_de_asteriscos + 1];
    memset(asteriscos, '*', total_de_asteriscos);
    asteriscos[total_de_asteriscos] = '\0';

    printf("%s\n", asteriscos);
    printf("* PARABÉNS %s, VOCÊ VENCEU! *\n", nomes_dos_jogadores[indice_do_jogador]);
    printf("%s\n\n", asteriscos);
}

int verificar_posicao(char tabuleiro[][3], int linha, int coluna)
{
    if (linha >= 0 && linha <= 2 && coluna >= 0 && coluna <= 2)
    {
        if (tabuleiro[linha][coluna] == ' ')
            return 0; // Posição disponível
        else
            return 1; // A posição já foi escolhida
    }
    return 2; // Posição inexistente
}

int verificar_linha(char tabuleiro[][3])
{
    int indice_do_vencedor = -1;

    for (int linha = 0; linha < 3; linha++)
    {
        if (tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2])
        {
            if (tabuleiro[linha][0] == 'X')
                indice_do_vencedor = 0;

            if (tabuleiro[linha][0] == 'O')
                indice_do_vencedor = 1;
        }
    }

    if (indice_do_vencedor != -1)
    {
        limpar_terminal();
        exibir_tabuleiro(tabuleiro);
        imprimir_vencedor(indice_do_vencedor);
        return 1;
    }

    return 0;
}

int verificar_coluna(char tabuleiro[][3])
{
    int indice_do_vencedor = -1;

    for (int coluna = 0; coluna < 3; coluna++)
    {
        if (tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna])
        {
            if (tabuleiro[0][coluna] == 'X')
                indice_do_vencedor = 0;

            if (tabuleiro[0][coluna] == 'O')
                indice_do_vencedor = 1;
        }
    }

    if (indice_do_vencedor != -1)
    {
        limpar_terminal();
        exibir_tabuleiro(tabuleiro);
        imprimir_vencedor(indice_do_vencedor);
        return 1;
    }

    return 0;
}

int verificar_diagonal(char tabuleiro[][3])
{
    int indice_do_vencedor = -1;

    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2])
    {
        if (tabuleiro[0][0] == 'X')
            indice_do_vencedor = 0;

        if (tabuleiro[0][0] == 'O')
            indice_do_vencedor = 1;
    }
    else if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0])
    {
        if (tabuleiro[0][2] == 'X')
            indice_do_vencedor = 0;

        if (tabuleiro[0][2] == 'O')
            indice_do_vencedor = 1;
    }

    if (indice_do_vencedor != -1)
    {
        limpar_terminal();
        exibir_tabuleiro(tabuleiro);
        imprimir_vencedor(indice_do_vencedor);
        return 1;
    }

    return 0;
}

void solicitar_posicao(char tabuleiro[][3], int indice_do_jogador)
{
    int linha, coluna, erro = 0;
    do
    {
        limpar_terminal();
        exibir_tabuleiro(tabuleiro);
        printf("-> SUA VEZ %s\n\n", nomes_dos_jogadores[indice_do_jogador]);

        switch (erro)
        {
        case 1:
            printf("Esse lugar já está ocupado, tente de novo.\n\n");
            break;
        case 2:
            printf("Essa posição não existe, tente de novo.\n\n");
            break;
        }

        printf("Informe uma linha: ");
        scanf("%d", &linha);
        printf("Informe uma coluna: ");
        scanf("%d", &coluna);

        linha--;
        coluna--;
        erro = verificar_posicao(tabuleiro, linha, coluna);
    } while (erro);

    if (indice_do_jogador == 0)
        tabuleiro[linha][coluna] = 'X';
    else
        tabuleiro[linha][coluna] = 'O';
}

int jogar(char tabuleiro[][3], int indice_do_jogador)
{
    solicitar_posicao(tabuleiro, indice_do_jogador);

    int fim_de_jogo = verificar_linha(tabuleiro);
    if (fim_de_jogo)
        return 1;

    fim_de_jogo = verificar_coluna(tabuleiro);
    if (fim_de_jogo)
        return 1;

    fim_de_jogo = verificar_diagonal(tabuleiro);
    if (fim_de_jogo)
        return 1;

    return 0;
}

void iniciar_partida()
{
    char tabuleiro[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '},
    };

    for (int i = 0; i < 9; i++)
    {
        int indice_do_jogador = i % 2;

        int fim_de_jogo = jogar(tabuleiro, indice_do_jogador);

        if (fim_de_jogo)
            return;
    }

    limpar_terminal();
    exibir_tabuleiro(tabuleiro);
    printf("***********************\n"
           "* EMPATE, FIM DE JOGO *\n"
           "***********************\n\n");
}

int menu()
{
    int opcao;
    do
    {
        printf("          Jogo da Velha\n\n");
        printf("Presione 0 para sair ou 1 para jogar.\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        puts("");

        switch (opcao)
        {
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            limpar_terminal();
            printf("Opcao invalida.\n\n");
        }
    } while (1);
}

void pegar_nome_do_jogador(int indice_do_jogador)
{
    char *nome_do_jogador = nomes_dos_jogadores[indice_do_jogador];
    char pegar_nome = 1;
    do
    {
        printf("Informe o nome do jogador %d: ", indice_do_jogador + 1);
        scanf(" %20[^\n]", nome_do_jogador);
        limpar_entrada_padrao();
        puts("");
        int tamanho_do_nome = (int)strlen(nome_do_jogador);
        if (tamanho_do_nome > 2)
        {
            pegar_nome = 0;
        }
        else
        {
            puts("O nome do jogador deve ter no mínimo três caracteres.\n");
        }
    } while (pegar_nome);
}

int main()
{
    int continuar = menu();

    if (continuar == 0)
        return 0;

    pegar_nome_do_jogador(0);
    pegar_nome_do_jogador(1);

    while (continuar)
    {
        iniciar_partida();
        continuar = menu();
    }

    return 0;
}
