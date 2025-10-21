#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3
#define TAM_HABILIDADE 5  // tamanho das matrizes de habilidade (5x5)

// ================================================================
// Funções auxiliares
// ================================================================
int dentroDoTabuleiro(int linha, int coluna) {
    return (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM);
}

int podePosicionar(int tabuleiro[TAM][TAM], int linha, int coluna, int dLinha, int dColuna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int novaLinha = linha + i * dLinha;
        int novaColuna = coluna + i * dColuna;
        if (!dentroDoTabuleiro(novaLinha, novaColuna)) return 0;
        if (tabuleiro[novaLinha][novaColuna] != 0) return 0;
    }
    return 1;
}

void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int dLinha, int dColuna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int novaLinha = linha + i * dLinha;
        int novaColuna = coluna + i * dColuna;
        tabuleiro[novaLinha][novaColuna] = 3;
    }
}

// ================================================================
// Função para criar e preencher as matrizes de habilidades
// ================================================================
void criarCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    // Cria uma forma de cone apontando para baixo
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= (TAM_HABILIDADE / 2 - i) && j <= (TAM_HABILIDADE / 2 + i))
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void criarCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    // Cria uma forma de cruz
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void criarOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    // Cria um losango (octaedro visto de frente)
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// ================================================================
// Função para aplicar uma habilidade ao tabuleiro
// ================================================================
void aplicarHabilidade(int tabuleiro[TAM][TAM],
                       int habilidade[TAM_HABILIDADE][TAM_HABILIDADE],
                       int origemLinha, int origemColuna) {
    int centro = TAM_HABILIDADE / 2;

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTab = origemLinha + (i - centro);
                int colunaTab = origemColuna + (j - centro);
                if (dentroDoTabuleiro(linhaTab, colunaTab) && tabuleiro[linhaTab][colunaTab] == 0) {
                    tabuleiro[linhaTab][colunaTab] = 5;
                }
            }
        }
    }
}

// ================================================================
// Função para exibir o tabuleiro formatado
// ================================================================
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("   TABULEIRO BATALHA NAVAL - NIVEL MESTRE\n\n");
    printf("    ");
    for (int letra = 0; letra < TAM; letra++) {
        printf("%c ", 'A' + letra);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d  ", i + 1);
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// ================================================================
// Função principal
// ================================================================
int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;

    // ============================================================
    // Posicionamento dos quatro navios (igual ao nível aventureiro)
    // ============================================================
    if (podePosicionar(tabuleiro, 2, 4, 0, 1)) posicionarNavio(tabuleiro, 2, 4, 0, 1); // horizontal
    if (podePosicionar(tabuleiro, 6, 1, 1, 0)) posicionarNavio(tabuleiro, 6, 1, 1, 0); // vertical
    if (podePosicionar(tabuleiro, 0, 0, 1, 1)) posicionarNavio(tabuleiro, 0, 0, 1, 1); // diagonal ↘
    if (podePosicionar(tabuleiro, 0, 9, 1, -1)) posicionarNavio(tabuleiro, 0, 9, 1, -1); // diagonal ↙

    // ============================================================
    // Criação das habilidades especiais
    // ============================================================
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // ============================================================
    // Aplicação das habilidades no tabuleiro
    // ============================================================
    aplicarHabilidade(tabuleiro, cone, 4, 4);      // cone no centro
    aplicarHabilidade(tabuleiro, cruz, 8, 8);      // cruz no canto inferior direito
    aplicarHabilidade(tabuleiro, octaedro, 1, 8);  // octaedro próximo ao topo direito

    // ============================================================
    // Exibição do tabuleiro final
    // ============================================================
    exibirTabuleiro(tabuleiro);

    printf("\nLegenda:\n");
    printf("0 = Água\n");
    printf("3 = Navio\n");
    printf("5 = Área afetada por habilidade\n");

    return 0;
}
