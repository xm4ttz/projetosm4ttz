#include <stdio.h>

int main(){
    char variavel;

    printf("Digite um valor\n");
    scanf("%c", &variavel);
    
    switch (variavel) {
    case 'a':
        printf("Código a ser executado se variável == a\n");
        printf("teste do case a");
    break;
    case 'b':
        printf("Código a ser executado se variável == b\n");
    break;
    default:
        printf("Código a ser executado se a variável não for 1 ou 2\n");
}

}