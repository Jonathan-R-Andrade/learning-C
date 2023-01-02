#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char nomes_dos_jogadores[2][21];
char asteriscos[48];

void exibir_tabuleiro(char tabuleiro[][3]);
void jogar();
void limpar_terminal();
void pegar_nome_do_jogador(int indiceDoJogador);
void gerar_asteriscos(int tamanhoDoNomeDoJogador);
void imprimir_vencedor(int indiceDoJogador);
void limpar_entrada_padrao();
char mudar_nome();
int menu();
int jogada(char tabuleiro[][3], int jogador);
int verificar_posicao(char tabuleiro[][3], int linha, int coluna, int jogador);
int verificar_linha(char tabuleiro[][3]);
int verificar_coluna(char tabuleiro[][3]);
int verificar_diagonal(char tabuleiro[][3]);

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
                pegar_nome_do_jogador(0);
                pegar_nome_do_jogador(1);
            }
            jogar();
            continuar = menu();
            if (continuar)
                nome = mudar_nome();
        }
    } while (continuar);
    return 0;
}

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
            exibir_tabuleiro(tabuleiro);
            printf("***********************\n"
                   "* EMPATE, FIM DE JOGO *\n"
                   "***********************\n\n");
        }
    }
}

int jogada(char tabuleiro[][3], int vez)
{
    int continuar = 1, linha, coluna, termino = 1;
    exibir_tabuleiro(tabuleiro);
    printf("-> SUA VEZ %s\n\n", nomes_dos_jogadores[vez]);
    do
    {
        printf("Informe uma linha: ");
        scanf("%d", &linha);
        printf("Informe uma coluna: ");
        scanf("%d", &coluna);
        linha--;
        coluna--;
        continuar = verificar_posicao(tabuleiro, linha, coluna, vez);
        termino = verificar_linha(tabuleiro);
        if (termino == 0)
        {
            return 0;
        }
        termino = verificar_coluna(tabuleiro);
        if (termino == 0)
        {
            return 0;
        }
        termino = verificar_diagonal(tabuleiro);
        if (termino == 0)
        {
            return 0;
        }
    } while (continuar);
    return 1;
}

void imprimir_vencedor(int indiceDoJogador)
{
    char *nomeDoJogador = nomes_dos_jogadores[indiceDoJogador];
    gerar_asteriscos(strlen(nomeDoJogador));
    printf("%s\n", asteriscos);
    printf("* PARABENS %s, VOCE VENCEU! *\n", nomes_dos_jogadores[indiceDoJogador]);
    printf("%s\n\n", asteriscos);
}

int verificar_posicao(char tabuleiro[][3], int linha, int coluna, int vez)
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
            limpar_terminal();
            return 0;
        }
        else
        {
            limpar_terminal();
            exibir_tabuleiro(tabuleiro);
            printf("-> %s\n\n", nomes_dos_jogadores[vez]);
            printf("Esse lugar ja esta ocupado, tente de novo.\n\n");
        }
    }
    else
    {
        limpar_terminal();
        exibir_tabuleiro(tabuleiro);
        printf("-> %s\n\n", nomes_dos_jogadores[vez]);
        printf("Essa posicao nao existe, tente de novo.\n\n");
    }
    return 1;
}

int verificar_linha(char tabuleiro[][3])
{
    for (int linha = 0; linha < 3; linha++)
    {
        if (tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2])
        {
            if (tabuleiro[linha][0] == 'X')
            {
                exibir_tabuleiro(tabuleiro);
                imprimir_vencedor(0);
                return 0;
            }
            if (tabuleiro[linha][0] == 'O')
            {
                exibir_tabuleiro(tabuleiro);
                imprimir_vencedor(1);
                return 0;
            }
        }
    }
    return 1;
}

int verificar_coluna(char tabuleiro[][3])
{
    for (int coluna = 0; coluna < 3; coluna++)
    {
        if (tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna])
        {
            if (tabuleiro[0][coluna] == 'X')
            {
                exibir_tabuleiro(tabuleiro);
                imprimir_vencedor(0);
                return 0;
            }
            if (tabuleiro[0][coluna] == 'O')
            {
                exibir_tabuleiro(tabuleiro);
                imprimir_vencedor(1);
                return 0;
            }
        }
    }
    return 1;
}

int verificar_diagonal(char tabuleiro[][3])
{
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2])
    {
        if (tabuleiro[0][0] == 'X')
        {
            exibir_tabuleiro(tabuleiro);
            imprimir_vencedor(0);
            return 0;
        }
        if (tabuleiro[0][0] == 'O')
        {
            exibir_tabuleiro(tabuleiro);
            imprimir_vencedor(1);
            return 0;
        }
    }
    else if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0])
    {
        if (tabuleiro[0][2] == 'X')
        {
            exibir_tabuleiro(tabuleiro);
            imprimir_vencedor(0);
            return 0;
        }
        if (tabuleiro[0][2] == 'O')
        {
            exibir_tabuleiro(tabuleiro);
            imprimir_vencedor(1);
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
            limpar_terminal();
            printf("Opcao invalida.\n\n");
        }
    } while (1);
}

void pegar_nome_do_jogador(int indiceDoJogador)
{
    char *nome_do_jogador = nomes_dos_jogadores[indiceDoJogador];
    char pegar_nome = 1;
    do
    {
        printf("Informe o nome do jogador %d: ", indiceDoJogador + 1);
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

void gerar_asteriscos(int tamanhoDoNomeDoJogador)
{
    int minimo = 28; // Tamanho do texto do vencedor mais o caractere nulo
    int total = minimo + tamanhoDoNomeDoJogador;
    memset(asteriscos, '*', total);
    asteriscos[total - 1] = '\0';
}

char mudar_nome(void)
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

void limpar_terminal(void)
{
    int i;
    for (i = 1; i < 101; i++)
    {
        printf("\n");
    }
}

void limpar_entrada_padrao()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    };
}
