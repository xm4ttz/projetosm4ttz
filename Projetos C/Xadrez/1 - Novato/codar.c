#include <stdio.h>
 
int main() {
    
    /*int i = 0;

    while (i <= 10)
    {
        if (i % 2 == 0)
        {
            printf("O numero %d é par!\n", i);
        }
        i++;
    }*/



    //=================================================================//
    //=================================================================//
    //=================================================================//



    /*int numero;

    do {

        printf("digite um numero par para sair do programa\n");
        scanf("%d", &numero);

        if (numero % 2 == 0){
            printf("%d é par!\n", numero);
        } else {
            printf("%d é impar!\n", numero);
        }
        

    } while (numero % 2 != 0);
    
    printf("você digitou um número par! Saindo do programa...\n");*/



    //=================================================================//
    //=================================================================//
    //=================================================================//


    int numero, i;

    printf("digite um número para calcularmos a tabuada:\n");
    scanf("%d", &numero);

    for (i = 1; i <= 10; i++)
    {
        printf("%d x %d = %d \n", numero, i, i * numero);
    }
   
    return 0;
}