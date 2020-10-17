/*
 * 'While' loop
 */

#include <stdlib.h>
#include <stdio.h>


int
main(int argc, char * argv[])
{

    int num_vueltas, i;

    num_vueltas = 8;

    i = 0;
    while (i < num_vueltas) {
        printf("Vuelta [%d]\n", i + 1);
        i = i + 1;  // i++
    }

    exit(EXIT_SUCCESS);
}
