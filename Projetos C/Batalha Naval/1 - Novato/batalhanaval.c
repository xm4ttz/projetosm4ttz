#include <stdio.h>

int main() {
    int TAM = 10;
    int TAM_NAVIO = 3;

    int tabuleiro[TAM][TAM];

    // Inicializa todas as posições com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Declara e inicializa navios
    int navio_horizontal[TAM_NAVIO];
    int navio_vertical[TAM_NAVIO];
    for (int i = 0; i < TAM_NAVIO; i++) {
        navio_horizontal[i] = 3;
        navio_vertical[i] = 3;
    }

    // Coordenadas iniciais dos navios
    int linha_inicial_horizontal = 2;
    int coluna_inicial_horizontal = 4;
    int linha_inicial_vertical = 6;
    int coluna_inicial_vertical = 1;

    // Posiciona o navio horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (coluna_inicial_horizontal + i < TAM) {
            tabuleiro[linha_inicial_horizontal][coluna_inicial_horizontal + i] = navio_horizontal[i];
        }
    }

    // Posiciona o navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (linha_inicial_vertical + i < TAM) {
            if (tabuleiro[linha_inicial_vertical + i][coluna_inicial_vertical] == 0) {
                tabuleiro[linha_inicial_vertical + i][coluna_inicial_vertical] = navio_vertical[i];
            }
        }
    }

    // ============================================================
    // Exibição do tabuleiro com coordenadas
    // ============================================================
    printf("   TABULEIRO BATALHA NAVAL\n\n");

    // Cabeçalho com letras A–J
    printf("    ");
    for (int letra = 0; letra < TAM; letra++) {
        printf("%c ", 'A' + letra);
    }
    printf("\n");

    // Impressão do tabuleiro com números 1–10 à esquerda
    for (int i = 0; i < TAM; i++) {
        printf("%2d  ", i + 1); // numeração das linhas (1 a 10)
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nCoordenadas do navio horizontal: %c%d até %c%d\n",
           'A' + coluna_inicial_horizontal, linha_inicial_horizontal + 1,
           'A' + (coluna_inicial_horizontal + TAM_NAVIO - 1), linha_inicial_horizontal + 1);

    printf("Coordenadas do navio vertical: %c%d até %c%d\n",
           'A' + coluna_inicial_vertical, linha_inicial_vertical + 1,
           'A' + coluna_inicial_vertical, linha_inicial_vertical + TAM_NAVIO);

    printf("\nLegenda: 0 = Água | 3 = Navio\n");

    return 0;
}
