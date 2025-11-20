#include <stdio.h>

int main() {
  int nota;

  printf("Digite a sua nota: \n");
  scanf("%d", &nota);

  if (nota < 60) {
    printf("Sua nota é F\n");
  } else if (nota < 70) {
    printf("Sua nota é D\n");
  } else if (nota < 80) {
    printf("Sua nota é C\n");
  } else if (nota < 90) {
    printf("Sua nota é B\n");
  } else {
    printf("Sua nota é A\n");
  }

  return 0;
}