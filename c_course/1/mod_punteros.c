/*
 * Imprime el valor absoluto de un numero
 */

#include <stdlib.h>
#include <stdio.h>

void
get_abs(int * n)
{
  if (*n < 0) {
    *n = -*n;
  }
}

int
main(int argc, char * argv[])
{
  int n = -4;

  get_abs(&n);

  printf("El valor absoluto es %d\n", n);

  exit(EXIT_SUCCESS);
}
