#include <stdio.h>

char tabuleiro[5][5];
int navio[3][2];
int tiro[2];
int tentativas = 0, acertos = 0;

void inicializaTabuleiro();
void mostraTabuleiro();
void iniciaNavios();
void darTiro();
int acertou(int linha, int coluna);
void dica();
void alteraTabuleiro(char pos);
int verificaPosicao();
void limparTerminal();

int main(void)
{
    int continuar = 1, c = 1;

    do
    {
        inicializaTabuleiro();
        iniciaNavios();
        do
        {
            mostraTabuleiro();
            darTiro();
        }
        while(acertos < 3);
        printf("Jogo terminado. Voce acertou os 3 navios em %d tentativas.\n\n", tentativas);
        mostraTabuleiro();
        do
        {
            puts("Deseja jogar de novo:");
            puts("0 para nao.");
            puts("1 para sim.");
            scanf("%d", &continuar);
            switch(continuar)
            {
            case 0:
                c = 0;
                break;
            case 1:
                c = 0;
                break;
            default:
                printf("Opcao invalida tente de novo.\n\n");
            }
        }
        while(c);
    }
    while(continuar);
    return 0;
}

void inicializaTabuleiro()
{
    int l, c;
    for(l = 0; l < 5; l++)
    {
        for(c = 0; c < 5; c++)
        {
            tabuleiro[l][c] = '~';
        }
    }
}

void mostraTabuleiro()
{
    puts("    1    2    3    4    5");
    int l,c;
    for(l = 0; l < 5; l++)
    {
        printf("%d   ", (l+1));
        for(c = 0; c < 5; c++)
        {
            if(c < 4)
                printf("%c    ", tabuleiro[l][c]);
            else
                printf("%c", tabuleiro[l][c]);
        }
        puts("");
        c = 0;
    }
    puts("");
}

void iniciaNavios()
{
    int i, ii, linha, coluna, continuar;

    for(i = 0; i < 3; i++)
    {
        do
        {
            continuar = 0;
            srand(time(NULL));
            linha = (rand() % 5) + 1;
            coluna = (rand() % 5) + 1;
            navio[i][0] = linha;
            navio[i][1] = coluna;
            for(ii = 0; ii < i; ii++)
            {
                if(navio[i][0] == navio[ii][0] && navio[ii][1] == navio[i][1])
                    continuar = 1;
            }
        }
        while(continuar);
    }
}

void darTiro()
{
    int linha, coluna;
    do
    {
        do
        {
            printf("Informe uma linha: ");
            scanf("%d", &linha);
            if(linha < 1 || linha > 5)
            {
                printf("Por favor informe um valor entre 1 e 5\n\n");
            }
        }
        while(linha < 1 || linha > 5);
        do
        {
            printf("Informe uma coluna: ");
            scanf("%d", &coluna);
            puts("");
            if(coluna < 1 || coluna > 5)
            {
                printf("Por favor informe um valor entre 1 e 5\n\n");
            }
        }
        while(coluna < 1 || coluna > 5);
        tiro[0] = linha;
        tiro[1] = coluna;
    }
    while(verificaPosicao());

    tentativas++;

    if(acertou(linha, coluna))
    {
        dica();
        printf("Voce acertou o tiro (%d,%d)\n\n", tiro[0], tiro[1]);
        alteraTabuleiro('X');

    }
    else
    {
        dica();
        alteraTabuleiro('*');
    }
}

int acertou(int linha, int coluna)
{
    int i;
    for(i = 0; i < 3; i++)
    {
        if(navio[i][0] == linha && navio[i][1] == coluna)
        {
            acertos++;
            return 1;
        }
    }
    return 0;
}

void alteraTabuleiro(char pos)
{
    tabuleiro[tiro[0]-1][tiro[1]-1] = pos;
}

void dica()
{
    int l,c, nl = 0, nc = 0;
    for(l = 0; l < 3; l++)
    {
        if(tiro[0] == navio[l][0])
            nl++;
    }
    for(c = 0; c < 3; c++)
    {
        if(tiro[1] == navio[c][1])
            nc++;
    }

    puts("Dica:");
    printf("Linha %d -> %d navio(s)\n", tiro[0], nl);
    printf("Coluna %d -> %d navio(s)\n\n", tiro[1], nc);
}

int verificaPosicao()
{
    if(tabuleiro[tiro[0]-1][tiro[1]-1] == '~')
        return 0;
    puts("Posicao ocupada, tente de novo.\n");
    return 1;
}

void limparTerminal()
{
    int i;
    for(i = 1; i <= 100; i++)
        puts("");
}
