#include <stdio.h>

int main() {
    // Variáveis da Carta 1
    char estado1;
    char codigo1[4];
    char cidade1[50];
    unsigned long int populacao1;
    float area1, pib1;
    int pontos_turisticos1;
    float densidade1, pib_per_capita1, super_poder1;

    // Variáveis da Carta 2
    char estado2;
    char codigo2[4];
    char cidade2[50];
    unsigned long int populacao2;
    float area2, pib2;
    int pontos_turisticos2;
    float densidade2, pib_per_capita2, super_poder2;

    // ======= Entrada de dados =======
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Digite o Codigo da Carta (ex: A01): ");
    scanf("%s", codigo1);
    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", cidade1);
    printf("Digite a Populacao: ");
    scanf("%lu", &populacao1);
    printf("Digite a Area (em km²): ");
    scanf("%f", &area1);
    printf("Digite o PIB (em bilhoes de reais): ");
    scanf("%f", &pib1);
    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontos_turisticos1);

    densidade1 = populacao1 / area1;
    pib_per_capita1 = (pib1 * 1e9) / populacao1;
    super_poder1 = populacao1 + area1 + pib1 + pontos_turisticos1 + pib_per_capita1 + (1.0 / densidade1);

    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Digite o Codigo da Carta (ex: A01): ");
    scanf("%s", codigo2);
    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", cidade2);
    printf("Digite a Populacao: ");
    scanf("%lu", &populacao2);
    printf("Digite a Area (em km²): ");
    scanf("%f", &area2);
    printf("Digite o PIB (em bilhoes de reais): ");
    scanf("%f", &pib2);
    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontos_turisticos2);

    densidade2 = populacao2 / area2;
    pib_per_capita2 = (pib2 * 1e9) / populacao2;
    super_poder2 = populacao2 + area2 + pib2 + pontos_turisticos2 + pib_per_capita2 + (1.0 / densidade2);

    // ======= Menu interativo antigo (desativado) =======
    /*
    int opcao;
    printf("\n=== MENU DE COMPARACAO ===\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Numero de Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("Escolha o atributo para comparar: ");
    scanf("%d", &opcao);

    printf("\n=== RESULTADO DA COMPARACAO ===\n");
    switch (opcao) {
        case 1: // População
            ...
            break;
        ...
    }
    */

    // ======= NOVO MENU - COMPARAÇÃO COM DOIS ATRIBUTOS =======
    int atributo1, atributo2;
    float valor1_c1 = 0, valor2_c1 = 0;
    float valor1_c2 = 0, valor2_c2 = 0;
    float soma_c1 = 0, soma_c2 = 0;

    printf("\n=== MENU DE COMPARACAO AVANCADA ===\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Numero de Pontos Turisticos\n");
    printf("5 - Densidade Demografica (vence o menor)\n");

    // Escolha do primeiro atributo
    do {
        printf("Escolha o primeiro atributo: ");
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > 5)
            printf("Opcao invalida! Tente novamente.\n");
    } while (atributo1 < 1 || atributo1 > 5);

    // Escolha do segundo atributo (não pode repetir)
    do {
        printf("Escolha o segundo atributo (diferente do primeiro): ");
        scanf("%d", &atributo2);
        if (atributo2 == atributo1 || atributo2 < 1 || atributo2 > 5)
            printf("Opcao invalida! Tente novamente.\n");
    } while (atributo2 == atributo1 || atributo2 < 1 || atributo2 > 5);

    // Função de apoio via switch (sem struct)
    switch (atributo1) {
        case 1: valor1_c1 = populacao1; valor1_c2 = populacao2; break;
        case 2: valor1_c1 = area1; valor1_c2 = area2; break;
        case 3: valor1_c1 = pib1; valor1_c2 = pib2; break;
        case 4: valor1_c1 = pontos_turisticos1; valor1_c2 = pontos_turisticos2; break;
        case 5: valor1_c1 = densidade1; valor1_c2 = densidade2; break;
    }

    switch (atributo2) {
        case 1: valor2_c1 = populacao1; valor2_c2 = populacao2; break;
        case 2: valor2_c1 = area1; valor2_c2 = area2; break;
        case 3: valor2_c1 = pib1; valor2_c2 = pib2; break;
        case 4: valor2_c1 = pontos_turisticos1; valor2_c2 = pontos_turisticos2; break;
        case 5: valor2_c1 = densidade1; valor2_c2 = densidade2; break;
    }

    // ======= COMPARAÇÃO =======
    printf("\n=== RESULTADO DA COMPARACAO ===\n");
    printf("Cidade 1: %s\nCidade 2: %s\n", cidade1, cidade2);
    printf("\nAtributo 1 (opcao %d): %.2f x %.2f\n", atributo1, valor1_c1, valor1_c2);
    printf("Atributo 2 (opcao %d): %.2f x %.2f\n", atributo2, valor2_c1, valor2_c2);

    // Ajuste da soma (lembrando que menor densidade vence)
    soma_c1 = valor1_c1 + valor2_c1;
    soma_c2 = valor1_c2 + valor2_c2;

    printf("\nSoma total dos atributos:\n");
    printf("%s = %.2f\n", cidade1, soma_c1);
    printf("%s = %.2f\n", cidade2, soma_c2);

    if (atributo1 == 5) soma_c1 += (1.0 / valor1_c1), soma_c2 += (1.0 / valor1_c2);
    if (atributo2 == 5) soma_c1 += (1.0 / valor2_c1), soma_c2 += (1.0 / valor2_c2);

    if (soma_c1 == soma_c2) {
        printf("\nResultado: Empate!\n");
    } else {
        printf("\nVencedora: %s\n", (soma_c1 > soma_c2 ? cidade1 : cidade2));
    }

    return 0;
}
