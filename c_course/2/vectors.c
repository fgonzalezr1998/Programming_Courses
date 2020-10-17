/*
 * Given two points A(ax, ay) and B(bx, by),
 * calculate the vector and its module and phase
 *
 **************************************************
 * For compiling: gcc -c -Wall -Wshadow vectors.c *
 * For linking: gcc -o vectors vector.o -lm       *
 **************************************************
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Two bidimensional points defined as constants:

#define AX 1.2
#define AY 0.5
#define BX -2.3
#define BY 4.7

float
module(float x, float y)
{
    // Returns de module of the vector V(x, y)

    return sqrt((pow(x, 2.0)) + (pow(y, 2.0)));
}

float
phase(float x, float y)
{
    // Returns the phase of the vector V(x, y)

    return atan(y / x);
}

int
main(int argc, char * argv[])
{
    float vx, vy;

    // Get Vector Coordinates

    vx = BX - AX;
    vy = BY - AY;

    // Print Vector Coordinates:

    printf("Vector: V = (%f, %f)\n", vx, vy);

    // Print vector module:

    printf("Module: %f\n", module(vx, vy));

    // Print vector phase:

    printf("Phase: %f\n", phase(vx, vy));

    exit(EXIT_SUCCESS);
}
