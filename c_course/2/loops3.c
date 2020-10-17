/*
 * 1º Read one number (float)
 * 2º Read number of input cases
 * 3º Read each number and print if it is greater, lower or equal
 * than the first one
 */

 // ¿How can we improve this code?

#include <stdlib.h>
#include <stdio.h>
//#include <err.h>

float
num_to_compare()
{
    float n;
    int ret;

    printf("Introduce first number: ");

    scanf("%f", &n);

    /*
    ret = scanf("%f", &n);
    if (ret != 1) {
        errx(EXIT_FAILURE, "%s\n", "Error reading input");
    }
    */

    return n;
}

int
n_inputs()
{
    int n;

    printf("%s", "Introduce Number of input cases: ");

    scanf("%d", &n);

    return n;
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
print_comparisons(int n2compare, int n_inputs)
{
    float n;

    printf("%s\n", "Introduce your numbers:");

    for (int i = 0; i < n_inputs; i++) {

        // Read next input:

        scanf("%f", &n);

        // Compare them:

        compare_nums(n2compare, n);
    }
}

int
main(int argc, char * argv[])
{
    int num_cases;
    float number2compare;

    // Read number to compare:

    number2compare = num_to_compare();

    // Read number of input cases:

    num_cases = n_inputs();

    // Print the comparisons:

    print_comparisons(number2compare, num_cases);

    exit(EXIT_SUCCESS);
}
