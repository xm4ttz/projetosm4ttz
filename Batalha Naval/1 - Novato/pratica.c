#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int matriz[3][3];
    int linha_aleatoria, coluna_aleatoria;
    int linha_usuario, coluna_usuario;
    int i, j;
    
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));
    
    // Preenche toda a matriz com zeros
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matriz[i][j] = 0;
        }
    }
    
    // Gera posições aleatórias para o número 1
    linha_aleatoria = rand() % 3;
    coluna_aleatoria = rand() % 3;
    
    // Coloca o número 1 na posição aleatória
    matriz[linha_aleatoria][coluna_aleatoria] = 1;
    
    /*// Mostra a matriz (opcional - para debug)
    printf("Matriz (apenas para verificação):\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }*/
    printf("\n");
    
    // Pede ao usuário para adivinhar a posição
    printf("Adivinhe a posição do número 1!\n");
    printf("Digite a linha (0-2): ");
    scanf("%d", &linha_usuario);
    printf("Digite a coluna (0-2): ");
    scanf("%d", &coluna_usuario);
    
    // Verifica se o usuário acertou
    if (linha_usuario == linha_aleatoria && coluna_usuario == coluna_aleatoria) {
        printf("\nParabéns! Você acertou! O número 1 está na posição [%d][%d]\n", 
               linha_aleatoria, coluna_aleatoria);
    } else {
        printf("\nQue pena! Você errou.\n");
        printf("O número 1 estava na posição [%d][%d]\n", 
               linha_aleatoria, coluna_aleatoria);
        printf("Você chutou a posição [%d][%d]\n", linha_usuario, coluna_usuario);
    }
    
    return 0;
}