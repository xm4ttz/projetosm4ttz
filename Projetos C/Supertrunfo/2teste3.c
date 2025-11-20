#include <stdio.h>

int main(){
    /*
    Atribuição simples (=)
    Atribuição com soma (+=)
    Atribuição com subtração (-=)
    Atribuição com multiplicação (*=)
    Atribuição com divisão (/=)
    */

    int numero1 = 10, numero2, resultado;

    resultado = 10;
    printf("Resultado: %d\n", resultado);

    //resultado = resultado + 20;
    resultado += 20;
    printf("Resultado: %d\n", resultado);

    //resultado = resultado - numero1;
    resultado -= numero1;
    printf("Resultado: %d\n", resultado);

    //resultado = resultado * numero1;
    resultado *= 5;
    printf("Resultado: %d\n", resultado);

    //resultado = resultado / numero1;
    resultado /= 2;
    printf("Resultado: %d\n", resultado);
    
}