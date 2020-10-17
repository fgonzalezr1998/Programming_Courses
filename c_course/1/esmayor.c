/*
 * Dados dos numeros enteros, imprime el mayor
 */

#include <stdlib.h>
#include <stdio.h>

void
impr_mayor(int a, int b)
{
  // Imprime el numero mayor

  if (a > b) {
    printf("%d es el mayor\n", a);
  } else if (b > a){
    printf("%d es el mayor\n", b);
  } else {
    printf("Son Iguales\n");
  }
}

void
f1()
{
  printf("Es un cero\n");
}

void
impr_num(int n)
{
  switch (n) {
    case 0:
      f1();
      break;
    case 1:
      printf("Es un uno\n");
      break;
    case 2:
      printf("Es un dos\n");
      break;
    default:
      printf("No se que numero es\n");
      break;
  }
}

int
main(int argc, char * argv[])
{
  // Declaracion:

  int n1, n2;

  // Inicializacion:

  n1 = 0;
  n2 = 12;

  impr_mayor(n1, n2);
  impr_num(n1);

  exit(EXIT_SUCCESS);
}
