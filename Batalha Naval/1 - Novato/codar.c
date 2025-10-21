#include <stdio.h>

int main() {
    
    int index;

    char * nomesAlunos [3][3] = {
        {"Aluno 1", "Pt: 30", "Mat: 90"}, 
        {"Aluno 2", "Pt: 60", "Mat: 60"}, 
        {"Aluno 3", "Pt: 90", "Mat: 30"}
    };

    printf("Digite o número do aluno que queira ver as notas... \n");
    printf("Para o aluno 0, Digite 0 \n");
    printf("Para o aluno 1, Digite 1 \n");
    printf("Para o aluno 2, Digite 2 \n");

    scanf("%d", &index);

    printf("As notas do aluno %s são %s , %s \n", nomesAlunos[index][0], nomesAlunos[index][1], nomesAlunos[index][2]);
    
    return 0;
}