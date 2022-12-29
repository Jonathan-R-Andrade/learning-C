#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char jogador[2][22];
char *ast;

void exibirTabuleiro(char tabuleiro[][3]);
void jogar(void);
void limparTerminal(void);
void pegarNomeDoJogador(int indiceDoJogador);
void asterisco(char jogador[22]);
char mudarNome(void);
int menu(void);
int jogada(char tabuleiro[][3], int jogador);
int verificaPosicao(char tabuleiro[][3], int linha, int coluna, int jogador);
int verificaLinha(char tabuleiro[][3]);
int verificaColuna(char tabuleiro[][3]);
int verificaDiagonal(char tabuleiro[][3]);

int main(void)
{
    char nome = 's';
    int continuar = menu();
    do
    {
        while (continuar)
        {
            if(nome == 's')
            {
                pegarNomeDoJogador(0);
                pegarNomeDoJogador(1);
            }
            jogar();
            continuar = menu();
            if(continuar)
                nome = mudarNome();
        }
    }
    while(continuar);
    free(ast);
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

    char tabuleiro[3][3] =
    {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
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
        continuar = verificaPosicao(tabuleiro, linha, coluna, vez);
        termino = verificaLinha(tabuleiro);
        if (termino == 0)
        {
            return 0;
        }
        termino = verificaColuna(tabuleiro);
        if (termino == 0)
        {
            return 0;
        }
        termino = verificaDiagonal(tabuleiro);
        if (termino == 0)
        {
            return 0;
        }
    }
    while (continuar);
    return 1;
}

int verificaPosicao(char tabuleiro[][3], int linha, int coluna, int vez)
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

int verificaLinha(char tabuleiro[][3])
{
    int linha;
    for (linha = 0; linha < 3; linha++)
    {
        if (tabuleiro[linha][0] == tabuleiro[linha][1])
        {
            if (tabuleiro[linha][1] == tabuleiro[linha][2])
            {
                if (tabuleiro[linha][0] == 'X')
                {
                    exibirTabuleiro(tabuleiro);
                    asterisco(jogador[0]);
                    printf("%s\n",ast);
                    printf("* PARABENS %s, VOCE VENCEU! *\n", jogador[0]);
                    printf("%s\n\n",ast);
                    return 0;
                }
                if (tabuleiro[linha][0] == 'O')
                {
                    exibirTabuleiro(tabuleiro);
                    asterisco(jogador[1]);
                    printf("%s\n",ast);
                    printf("* PARABENS %s, VOCE VENCEU! *\n", jogador[1]);
                    printf("%s\n\n",ast);
                    return 0;
                }
            }
        }
    }
    return 1;
}

int verificaColuna(char tabuleiro[][3])
{
    int coluna;
    for (coluna = 0; coluna < 3; coluna++)
    {
        if (tabuleiro[0][coluna] == tabuleiro[1][coluna])
        {
            if (tabuleiro[1][coluna] == tabuleiro[2][coluna])
            {
                if (tabuleiro[0][coluna] == 'X')
                {
                    exibirTabuleiro(tabuleiro);
                    asterisco(jogador[0]);
                    printf("%s\n",ast);
                    printf("* PARABENS %s, VOCE VENCEU! *\n", jogador[0]);
                    printf("%s\n\n",ast);
                    return 0;
                }
                if (tabuleiro[0][coluna] == 'O')
                {
                    exibirTabuleiro(tabuleiro);
                    asterisco(jogador[1]);
                    printf("%s\n",ast);
                    printf("* PARABENS %s, VOCE VENCEU! *\n", jogador[1]);
                    printf("%s\n\n",ast);
                    return 0;
                }
            }
        }
    }
    return 1;
}

int verificaDiagonal(char tabuleiro[][3])
{
    if (tabuleiro[0][0] == tabuleiro[1][1])
    {
        if (tabuleiro[1][1] == tabuleiro[2][2])
        {
            if (tabuleiro[0][0] == 'X')
            {
                exibirTabuleiro(tabuleiro);
                asterisco(jogador[0]);
                printf("%s\n",ast);
                printf("* PARABENS %s, VOCE VENCEU! *\n", jogador[0]);
                printf("%s\n\n",ast);
                return 0;
            }
            if (tabuleiro[0][0] == 'O')
            {
                exibirTabuleiro(tabuleiro);
                asterisco(jogador[1]);
                printf("%s\n",ast);
                printf("* PARABENS %s, VOCE VENCEU! *\n", jogador[1]);
                printf("%s\n\n",ast);
                return 0;
            }
        }
    }
    if (tabuleiro[0][2] == tabuleiro[1][1])
    {
        if (tabuleiro[1][1] == tabuleiro[2][0])
        {
            if (tabuleiro[0][2] == 'X')
            {
                exibirTabuleiro(tabuleiro);
                asterisco(jogador[0]);
                printf("%s\n",ast);
                printf("* PARABENS %s, VOCE VENCEU! *\n", jogador[0]);
                printf("%s\n\n",ast);
                return 0;
            }
            if (tabuleiro[0][2] == 'O')
            {
                exibirTabuleiro(tabuleiro);
                asterisco(jogador[1]);
                printf("%s\n",ast);
                printf("* PARABENS %s, VOCE VENCEU! *\n", jogador[1]);
                printf("%s\n\n",ast);
                return 0;
            }
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
    }
    while (1);
}

void pegarNomeDoJogador(int indiceDoJogador)
{
    char continuar = 's';
    do
    {
        printf("Informe o nome do jogador %d: ", indiceDoJogador+1);
        scanf("%s", jogador[indiceDoJogador]);
        puts("");
        int tamanho = (int) strlen(jogador[indiceDoJogador]);
        if(tamanho < 21 && tamanho > 0)
        {
            continuar = 'n';
        }
        else
        {
            puts("Por favor informe um nome com 1 ate 20 caractes.\n");
        }
    }
    while(continuar != 'n');
}

void asterisco(char jogador[22])
{
    ast = malloc(48 * sizeof(char));
    int tamanho = strlen(jogador)+27;
    memset(ast, '*', tamanho);
    ast[tamanho] = '\0';
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
        switch(opcao)
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
    }
    while(continuar);
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
