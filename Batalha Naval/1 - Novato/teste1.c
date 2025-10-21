#include <stdio.h>
 
int main() {
    int numeros[5];
 
    printf("Digite o primeiro número: \n");
    scanf("%d", &numeros[0]);

    printf("Digite o segundo número: \n");
    scanf("%d", &numeros[1]);
    
    printf("Digite o terceiro número: \n");
    scanf("%d", &numeros[2]);
    
    printf("Digite o quarto número: \n");
    scanf("%d", &numeros[3]);
    
    printf("Digite o quinto número: \n");
    scanf("%d", &numeros[4]);

    printf("Segue os números na ordem do vetor: %d, %d, %d, %d, %d", numeros[0], numeros[1], numeros[2], numeros[3], numeros[4]);
    
    return 0;
}