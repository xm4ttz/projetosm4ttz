#include <stdio.h>

int main() {
    // Variáveis para a Carta 1
    char estado1;
    char codigo1[4];
    char cidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1; // em bilhões
    int pontos_turisticos1;
    float densidade1;
    float pib_per_capita1;
    float super_poder1;

    // Variáveis para a Carta 2
    char estado2;
    char codigo2[4];
    char cidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2; // em bilhões
    int pontos_turisticos2;
    float densidade2;
    float pib_per_capita2;
    float super_poder2;

    // ======= Entrada de dados Carta 1 =======
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

    // Cálculos Carta 1
    densidade1 = (float) populacao1 / area1;
    pib_per_capita1 = (pib1 * 1000000000.0f) / (float) populacao1;
    super_poder1 = (float) populacao1 + area1 + pib1 + (float) pontos_turisticos1 + pib_per_capita1 + (1.0f / densidade1);

    // ======= Entrada de dados Carta 2 =======
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

    // Cálculos Carta 2
    densidade2 = (float) populacao2 / area2;
    pib_per_capita2 = (pib2 * 1000000000.0f) / (float) populacao2;
    super_poder2 = (float) populacao2 + area2 + pib2 + (float) pontos_turisticos2 + pib_per_capita2 + (1.0f / densidade2);

    // ======= Exibição das cartas =======
    printf("\n=== Carta 1 ===\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("Populacao: %lu\n", populacao1);
    printf("Area: %.2f km²\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita1);
    printf("Super Poder: %.2f\n", super_poder1);

    printf("\n=== Carta 2 ===\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("Populacao: %lu\n", populacao2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita2);
    printf("Super Poder: %.2f\n", super_poder2);

    // ======= Comparações =======
    printf("\n=== Comparacao de Cartas ===\n");

    printf("Populacao: %s\n", (populacao1 > populacao2) ? "Carta 1 venceu" : (populacao2 > populacao1) ? "Carta 2 venceu" : "Empate");
    printf("Area: %s\n", (area1 > area2) ? "Carta 1 venceu" : (area2 > area1) ? "Carta 2 venceu" : "Empate");
    printf("PIB: %s\n", (pib1 > pib2) ? "Carta 1 venceu" : (pib2 > pib1) ? "Carta 2 venceu" : "Empate");
    printf("Pontos Turisticos: %s\n", (pontos_turisticos1 > pontos_turisticos2) ? "Carta 1 venceu" : (pontos_turisticos2 > pontos_turisticos1) ? "Carta 2 venceu" : "Empate");
    printf("Densidade Populacional: %s\n", (densidade1 < densidade2) ? "Carta 1 venceu" : (densidade2 < densidade1) ? "Carta 2 venceu" : "Empate");
    printf("PIB per Capita: %s\n", (pib_per_capita1 > pib_per_capita2) ? "Carta 1 venceu" : (pib_per_capita2 > pib_per_capita1) ? "Carta 2 venceu" : "Empate");
    printf("Super Poder: %s\n", (super_poder1 > super_poder2) ? "Carta 1 venceu" : (super_poder2 > super_poder1) ? "Carta 2 venceu" : "Empate");

    // ======= Comparação de um único atributo =======
    printf("\n=== Comparacao de Cartas (Atributo: Populacao) ===\n");
    printf("Carta 1 - %s (%c): %lu habitantes\n", cidade1, estado1, populacao1);
    printf("Carta 2 - %s (%c): %lu habitantes\n", cidade2, estado2, populacao2);

    return 0;
}
