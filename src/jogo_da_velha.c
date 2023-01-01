#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char jogador[2][21];
char asteriscos[48];

void exibirTabuleiro(char tabuleiro[][3]);
void jogar(void);
void limparTerminal(void);
void pegarNomeDoJogador(int indiceDoJogador);
void gerarAsteriscos(int tamanhoDoNomeDoJogador);
void imprimirVencedor(int indiceDoJogador);
void limparEntradaPadrao(void);
char mudarNome(void);
int menu(void);
int jogada(char tabuleiro[][3], int jogador);
int verificarPosicao(char tabuleiro[][3], int linha, int coluna, int jogador);
int verificarLinha(char tabuleiro[][3]);
int verificarColuna(char tabuleiro[][3]);
int verificarDiagonal(char tabuleiro[][3]);

int main(void)
{
    char nome = 's';
    int continuar = menu();
    do
    {
        while (continuar)
        {
            if (nome == 's')
            {
                pegarNomeDoJogador(0);
                pegarNomeDoJogador(1);
            }
            jogar();
            continuar = menu();
            if (continuar)
                nome = mudarNome();
        }
    } while (continuar);
    return 0;
}

void exibirTabuleiro(char tabuleiro[][3])
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

void jogar(void)
{
    char tabuleiro[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '},
    };

    int continuar = 1;
    int i;
    for (i = 0; i < 9; i++)
    {
        if (i % 2 == 0)
        {
            continuar = jogada(tabuleiro, (i % 2));
        }
        else
        {
            continuar = jogada(tabuleiro, (i % 2));
        }
        if (continuar == 0)
        {
            break;
        }
        if (i == 8)
        {
            exibirTabuleiro(tabuleiro);
            printf("***********************\n"
                   "* EMPATE, FIM DE JOGO *\n"
                   "***********************\n\n");
        }
    }
}

int jogada(char tabuleiro[][3], int vez)
{
    int continuar = 1, linha, coluna, termino = 1;
    exibirTabuleiro(tabuleiro);
    printf("-> SUA VEZ %s\n\n", jogador[vez]);
    do
    {
        printf("Informe uma linha: ");
        scanf("%d", &linha);
        printf("Informe uma coluna: ");
        scanf("%d", &coluna);
        linha--;
        coluna--;
        continuar = verificarPosicao(tabuleiro, linha, coluna, vez);
        termino = verificarLinha(tabuleiro);
        if (termino == 0)
        {
            return 0;
        }
        termino = verificarColuna(tabuleiro);
        if (termino == 0)
        {
            return 0;
        }
        termino = verificarDiagonal(tabuleiro);
        if (termino == 0)
        {
            return 0;
        }
    } while (continuar);
    return 1;
}

void imprimirVencedor(int indiceDoJogador)
{
    char *nomeDoJogador = jogador[indiceDoJogador];
    gerarAsteriscos(strlen(nomeDoJogador));
    printf("%s\n", asteriscos);
    printf("* PARABENS %s, VOCE VENCEU! *\n", jogador[indiceDoJogador]);
    printf("%s\n\n", asteriscos);
}

int verificarPosicao(char tabuleiro[][3], int linha, int coluna, int vez)
{
    if (linha >= 0 && linha <= 2 && coluna >= 0 && coluna <= 2)
    {
        if (tabuleiro[linha][coluna] == ' ')
        {
            char XO = ' ';
            if (vez == 0)
            {
                XO = 'X';
            }
            else
            {
                XO = 'O';
            }
            tabuleiro[linha][coluna] = XO;
            limparTerminal();
            return 0;
        }
        else
        {
            limparTerminal();
            exibirTabuleiro(tabuleiro);
            printf("-> %s\n\n", jogador[vez]);
            printf("Esse lugar ja esta ocupado, tente de novo.\n\n");
        }
    }
    else
    {
        limparTerminal();
        exibirTabuleiro(tabuleiro);
        printf("-> %s\n\n", jogador[vez]);
        printf("Essa posicao nao existe, tente de novo.\n\n");
    }
    return 1;
}

int verificarLinha(char tabuleiro[][3])
{
    for (int linha = 0; linha < 3; linha++)
    {
        if (tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2])
        {
            if (tabuleiro[linha][0] == 'X')
            {
                exibirTabuleiro(tabuleiro);
                imprimirVencedor(0);
                return 0;
            }
            if (tabuleiro[linha][0] == 'O')
            {
                exibirTabuleiro(tabuleiro);
                imprimirVencedor(1);
                return 0;
            }
        }
    }
    return 1;
}

int verificarColuna(char tabuleiro[][3])
{
    for (int coluna = 0; coluna < 3; coluna++)
    {
        if (tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna])
        {
            if (tabuleiro[0][coluna] == 'X')
            {
                exibirTabuleiro(tabuleiro);
                imprimirVencedor(0);
                return 0;
            }
            if (tabuleiro[0][coluna] == 'O')
            {
                exibirTabuleiro(tabuleiro);
                imprimirVencedor(1);
                return 0;
            }
        }
    }
    return 1;
}

int verificarDiagonal(char tabuleiro[][3])
{
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2])
    {
        if (tabuleiro[0][0] == 'X')
        {
            exibirTabuleiro(tabuleiro);
            imprimirVencedor(0);
            return 0;
        }
        if (tabuleiro[0][0] == 'O')
        {
            exibirTabuleiro(tabuleiro);
            imprimirVencedor(1);
            return 0;
        }
    }
    else if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0])
    {
        if (tabuleiro[0][2] == 'X')
        {
            exibirTabuleiro(tabuleiro);
            imprimirVencedor(0);
            return 0;
        }
        if (tabuleiro[0][2] == 'O')
        {
            exibirTabuleiro(tabuleiro);
            imprimirVencedor(1);
            return 0;
        }
    }
    return 1;
}

int menu(void)
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
            limparTerminal();
            printf("Opcao invalida.\n\n");
        }
    } while (1);
}

void pegarNomeDoJogador(int indiceDoJogador)
{
    char *nome_do_jogador = jogador[indiceDoJogador];
    char pegar_nome = 1;
    do
    {
        printf("Informe o nome do jogador %d: ", indiceDoJogador + 1);
        scanf(" %20[^\n]", nome_do_jogador);
        limparEntradaPadrao();
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

void gerarAsteriscos(int tamanhoDoNomeDoJogador)
{
    int minimo = 28; // Tamanho do texto do vencedor mais o caractere nulo
    int total = minimo + tamanhoDoNomeDoJogador;
    memset(asteriscos, '*', total);
    asteriscos[total - 1] = '\0';
}

char mudarNome(void)
{
    char opcao, resposta;
    int continuar;
    do
    {
        printf("Voce deseja mudar o nome dos jogadores (S/s | N/n)? ");
        scanf(" %c", &opcao);
        puts("");
        switch (opcao)
        {
        case 'S':
            continuar = 0;
            resposta = 's';
            break;
        case 's':
            continuar = 0;
            resposta = 's';
            break;
        case 'N':
            continuar = 0;
            resposta = 'n';
            break;
        case 'n':
            continuar = 0;
            resposta = 'n';
            break;
        default:
            printf("Por favor escolha \"S/s\" para sim e \"N/n\" para nao.\n\n");
            continuar = 1;
        }
    } while (continuar);
    return resposta;
}

void limparTerminal(void)
{
    int i;
    for (i = 1; i < 101; i++)
    {
        printf("\n");
    }
}

void limparEntradaPadrao()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    };
}
