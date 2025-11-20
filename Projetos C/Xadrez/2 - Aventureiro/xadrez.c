#include <stdio.h>

int main() {
    // =====================================================
    // SIMULAÇÃO DO MOVIMENTO DAS PEÇAS DE XADREZ
    // Torre → for
    // Bispo → while
    // Rainha → do-while
    // Cavalo → loops aninhados
    // =====================================================

    // ------------------------------
    // Movimento da Torre (FOR)
    // ------------------------------
    int casasTorre = 5;
    printf("=== Movimento da Torre ===\n");
    for (int i = 1; i <= casasTorre; i++) {
        printf("Direita (%d)\n", i);
    }

    // ------------------------------
    // Movimento do Bispo (WHILE)
    // ------------------------------
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
    int casasRainha = 8;
    int contadorRainha = 1;
    printf("\n=== Movimento da Rainha ===\n");
    do {
        printf("Esquerda (%d)\n", contadorRainha);
        contadorRainha++;
    } while (contadorRainha <= casasRainha);

    // =====================================================
    // DESAFIO NÍVEL AVENTUREIRO — Movimento do Cavalo
    // =====================================================

    int opcao;
    do {
        // Menu de direções para o Cavalo
        printf("\n=== Movimento do Cavalo ===\n");
        printf("Escolha a direção inicial:\n");
        printf("1. Cima\n");
        printf("2. Baixo\n");
        printf("3. Esquerda\n");
        printf("4. Direita\n");
        printf("5. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        // Loop externo para controlar a execução
        for (int escolha = opcao; escolha <= opcao; escolha++) {

            // Movimento de duas casas na direção escolhida
            int i = 1;
            do {
                switch (escolha) {
                    case 1: printf("Cima (%d)\n", i); break;
                    case 2: printf("Baixo (%d)\n", i); break;
                    case 3: printf("Esquerda (%d)\n", i); break;
                    case 4: printf("Direita (%d)\n", i); break;
                }
                i++;
            } while (i <= 2); // duas casas na direção principal

            // Movimento de uma casa perpendicular (loop aninhado)
            int j = 1;
            while (j <= 1) {
                switch (escolha) {
                    case 1: printf("Direita (%d)\n", j); break;  // se subiu, move à direita
                    case 2: printf("Esquerda (%d)\n", j); break; // se desceu, move à esquerda
                    case 3: printf("Cima (%d)\n", j); break;     // se foi esquerda, sobe
                    case 4: printf("Baixo (%d)\n", j); break;    // se foi direita, desce
                }
                j++;
            }
        }

    } while (opcao != 5);

    printf("\n=== Fim da Simulação ===\n");
    return 0;
}
