/*
 * 'for' loop
 */

#include <stdlib.h>
#include <stdio.h>

#define NVUELTAS 8

int
main(int argc, char * argv[])
{
    for (int i = 0; i < NVUELTAS; i++) {
        printf("Vuelta [%d]\n", i + 1);
    }

    exit(EXIT_SUCCESS);
}
