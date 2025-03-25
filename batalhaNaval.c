// Biblioteca
#include <stdio.h>

// Função Principal
int main()
{
    // Variaveis
    int tabuleiro[10][10] = {0};
    int navio = 3;
    int linha, coluna;
    int opcao;

    // Posiciona os navios uma vez só
    tabuleiro[0][3] = navio;
    tabuleiro[1][3] = navio;
    tabuleiro[2][3] = navio;

    tabuleiro[6][5] = navio;
    tabuleiro[6][6] = navio;
    tabuleiro[6][7] = navio;

    tabuleiro[2][5] = navio;
    tabuleiro[3][6] = navio;
    tabuleiro[4][7] = navio;

    tabuleiro[6][3] = navio;
    tabuleiro[7][2] = navio;
    tabuleiro[8][1] = navio;

    do
    {
        // Inicio do Jogo Com Menu
        printf("\n===========================\n");
        printf("     BATALHA NAVAL \n");
        printf("===========================\n");
        printf("1. Jogar\n");
        printf("2. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao)
        {
        case 1:
            // Desenha o cabeçalho com letras
            printf("  A B C D E F G H I J\n");

            for (int i = 0; i < 10; i++)
            {
                printf("%d ", i + 1);
                for (int j = 0; j < 10; j++)
                {
                    if (tabuleiro[i][j] == -1)
                    {
                        printf("5 "); // Acerto
                    }
                    else if (tabuleiro[i][j] == -2)
                    {
                        printf("0 "); // Água
                    }
                    else
                    {
                        printf(". "); // Água escondida
                    }
                }
                printf("\n");
            }

            // Recebe a jogada
            printf("\nEscolha linha (1 - 10): ");
            scanf("%d", &linha);
            printf("Escolha coluna (A - J): ");
            char colunaLetra;
            scanf(" %c", &colunaLetra);

            // Converte a letra em número
            coluna = colunaLetra - 'A';

            if (linha < 1 || linha > 10 || coluna < 0 || coluna > 9)
            {
                printf("\nCoordenadas invalidas! Tente novamente.\n");
            }
            else
            {
                linha--; // Ajusta para índice 0

                // Verifica se acertou
                if (tabuleiro[linha][coluna] == navio)
                {
                    printf("\n🎯 Acertou um navio!\n");
                    tabuleiro[linha][coluna] = -1; // Marca como acertado
                }
                else if (tabuleiro[linha][coluna] == 0)
                {
                    printf("\n Errou, so agua.\n");
                    tabuleiro[linha][coluna] = -2; // Marca como erro
                }
                else
                {
                    printf("\n Voce ja tentou aqui!\n");
                }
            }
            break;

        case 2:
            printf("\nSaindo do Jogo... 🚪\n");
            break;

        default:
            printf("\nOpcao invalida. Tente novamente.\n");
            break;
        }
    } while (opcao != 2);

    return 0;
}

