#include <stdio.h>

int main() {
    // =====================================================
    // SIMULAÇÃO DO MOVIMENTO DAS PEÇAS DE XADREZ
    // Torre → movimento horizontal/vertical
    // Bispo → movimento diagonal
    // Rainha → movimento em qualquer direção
    // =====================================================

    // ------------------------------
    // Movimento da Torre (FOR)
    // ------------------------------
    // A torre se move 5 casas para a direita.
    int casasTorre = 5;
    printf("=== Movimento da Torre ===\n");
    for (int i = 1; i <= casasTorre; i++) {
        printf("Direita (%d)\n", i);
    }

    // ------------------------------
    // Movimento do Bispo (WHILE)
    // ------------------------------
    // O bispo se move 5 casas na diagonal superior direita.
    int casasBispo = 5;
    int contadorBispo = 1;
    printf("\n=== Movimento do Bispo ===\n");
    while (contadorBispo <= casasBispo) {
        printf("Cima, Direita (%d)\n", contadorBispo);
        contadorBispo++;
    }

    // ------------------------------
    // Movimento da Rainha (DO-WHILE)
    // ------------------------------
    // A rainha se move 8 casas para a esquerda.
    int casasRainha = 8;
    int contadorRainha = 1;
    printf("\n=== Movimento da Rainha ===\n");
    do {
        printf("Esquerda (%d)\n", contadorRainha);
        contadorRainha++;
    } while (contadorRainha <= casasRainha);

    // Fim do programa
    printf("\n=== Fim da Simulação ===\n");
    return 0;
}
