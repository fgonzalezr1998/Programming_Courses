#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXSTR 7

typedef struct TipoCarta TipoCarta;
struct TipoCarta {
    char palo[MAXSTR];
    int valor;
};

int
main(int argc, char * argv[])
{
    TipoCarta carta;

    strncpy(carta.palo, "copas", sizeof(char) * MAXSTR);

    carta.valor = 8;

    printf("Carta: %d de %s\n", carta.valor, carta.palo);

    exit(EXIT_SUCCESS);
}
