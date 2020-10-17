/*
 * 1º Read one number (float)
 * 2º Read each number (until 0.0) and print if it is greater, lower or equal
 * than the first one
 */

#include <stdlib.h>
#include <stdio.h>
#include <err.h>
#include <string.h>

#define MAXSTR 32

void read_float(float * out);

int
is_dot(char c)
{
    return c == '.';
}

int
is_num(char c)
{
    int char_pos;
    char init_char, fin_char;

    init_char = '0';
    fin_char = '9';

    char_pos = c;

    return char_pos >= (int)init_char && char_pos <= (int)fin_char;
}

int
str_ok(char * s)
{
    /*
     * Returns true (1) if 's' is a valid string and false (0) otherwise
     * *****************¿What is a valid string?***********************
     * It has to have only onde dot (.) and the rest of the chars must*
     * be numbers                                                     *
     ******************************************************************
     */

    int n_dots = 0;

    for (int i = 0; i < strlen(s); i++) {
        // printf("%c\n", s[i]);
        if (is_dot(s[i])) {
            n_dots++;
        } else {

            if (!is_num(s[i])) {
                return 0;
            }
        }
    }

    return n_dots <= 1;
}

float
num_to_compare()
{
    float n;
    int ret;

    printf("Introduce first number: ");

    read_float(&n);

    return n;
}

void
str2float(char * s, float * out)
{
    /*
     * Convert 's' string to float and stores it at 'out'
     */

    if (str_ok(s)) {
        *out = (float)atof(s);
    } else {
        errx(EXIT_FAILURE, "%s\n", "[ERROR] Invalid Input!");
    }
}

void
read_float(float * out)
{
    // Define an string (array of chars):

    char str[MAXSTR];

    if (fgets(str, MAXSTR + 1, stdin) == NULL) {
        errx(EXIT_FAILURE, "%s\n", "[ERROR] Failure reading");
    }

    // Delete the '\n' char

    str[strlen(str) - 1] = '\0';

    str2float(str, out);
}

void
compare_nums(float n2compare, float n)
{
    if (n > n2compare) {
        printf("[%f] is greater than [%f]\n", n, n2compare);
    } else if (n < n2compare){
        printf("[%f] is lower than [%f]\n", n, n2compare);
    } else {
        printf("[%f] and [%f] are equals\n", n, n2compare);
    }
}

void
print_comparisons(int n2compare)
{
    float n;

    do{
        read_float(&n);
        if (n != 0.0) {
            compare_nums(n2compare, n);
        }
    }while (n != 0.0);
}

int
main(int argc, char * argv[])
{
    float number2compare;

    // Read number to compare:

    number2compare = num_to_compare();

    print_comparisons(number2compare);

    exit(EXIT_SUCCESS);
}
