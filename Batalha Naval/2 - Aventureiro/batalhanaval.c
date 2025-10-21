#include <stdio.h>

// ================================================================
// Constantes globais
// ================================================================
#define TAM 10         // Tamanho do tabuleiro (10x10)
#define TAM_NAVIO 3    // Tamanho fixo dos navios

// ================================================================
// Função auxiliar: valida se uma posição está dentro do tabuleiro
// ================================================================
int dentroDoTabuleiro(int linha, int coluna) {
    return (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM);
}

// ================================================================
// Função auxiliar: verifica se há sobreposição de navio
// ================================================================
int podePosicionar(int tabuleiro[TAM][TAM], int linha, int coluna, int dLinha, int dColuna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int novaLinha = linha + i * dLinha;
        int novaColuna = coluna + i * dColuna;
        if (!dentroDoTabuleiro(novaLinha, novaColuna)) {
            return 0; // fora do tabuleiro
        }
        if (tabuleiro[novaLinha][novaColuna] != 0) {
            return 0; // posição já ocupada
        }
    }
    return 1; // pode posicionar
}

// ================================================================
// Função auxiliar: posiciona o navio no tabuleiro
// ================================================================
void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int dLinha, int dColuna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int novaLinha = linha + i * dLinha;
        int novaColuna = coluna + i * dColuna;
        tabuleiro[novaLinha][novaColuna] = 3;
    }
}

// ================================================================
// Função principal
// ================================================================
int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa todas as posições do tabuleiro com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ============================================================
    // POSICIONAMENTO DOS 4 NAVIOS
    // ============================================================
    // Navio 1 – Horizontal
    int l1 = 2, c1 = 4;
    if (podePosicionar(tabuleiro, l1, c1, 0, 1)) {
        posicionarNavio(tabuleiro, l1, c1, 0, 1);
    }

    // Navio 2 – Vertical
    int l2 = 6, c2 = 1;
    if (podePosicionar(tabuleiro, l2, c2, 1, 0)) {
        posicionarNavio(tabuleiro, l2, c2, 1, 0);
    }

    // Navio 3 – Diagonal principal (↘)
    int l3 = 0, c3 = 0;
    if (podePosicionar(tabuleiro, l3, c3, 1, 1)) {
        posicionarNavio(tabuleiro, l3, c3, 1, 1);
    }

    // Navio 4 – Diagonal secundária (↙)
    int l4 = 0, c4 = 9;
    if (podePosicionar(tabuleiro, l4, c4, 1, -1)) {
        posicionarNavio(tabuleiro, l4, c4, 1, -1);
    }

    // ============================================================
    // EXIBIÇÃO DO TABULEIRO
    // ============================================================
    printf("   TABULEIRO BATALHA NAVAL - NIVEL AVENTUREIRO\n\n");

    // Cabeçalho com letras A–J
    printf("    ");
    for (int letra = 0; letra < TAM; letra++) {
        printf("%c ", 'A' + letra);
    }
    printf("\n");

    // Impressão das linhas numeradas (1–10)
    for (int i = 0; i < TAM; i++) {
        printf("%2d  ", i + 1);
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // ============================================================
    // PRINTFs das coordenadas dos 4 navios
    // ============================================================
    printf("\nCoordenadas dos navios:\n");

    printf("1️⃣ Horizontal: %c%d até %c%d\n",
           'A' + c1, l1 + 1,
           'A' + (c1 + TAM_NAVIO - 1), l1 + 1);

    printf("2️⃣ Vertical: %c%d até %c%d\n",
           'A' + c2, l2 + 1,
           'A' + c2, l2 + TAM_NAVIO);

    printf("3️⃣ Diagonal ↘: %c%d até %c%d\n",
           'A' + c3, l3 + 1,
           'A' + (c3 + TAM_NAVIO - 1), l3 + TAM_NAVIO);

    printf("4️⃣ Diagonal ↙: %c%d até %c%d\n",
           'A' + c4, l4 + 1,
           'A' + (c4 - (TAM_NAVIO - 1)), l4 + TAM_NAVIO);

    printf("\nLegenda: 0 = Água | 3 = Navio\n");

    return 0;
}
