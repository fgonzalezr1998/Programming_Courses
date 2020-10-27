#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <err.h>
#include "my_list/my_list.h"

#define MAXSTR 10

int
itemOk(int c)
{
    return c >= '1' && c <= '4';
}

int
read_char(char * output)
{
    /*
     * Get the latest char read by input
     * ¿How can i change this procedure to
     * get the first char?
     */
    char c;
    int num_chars = 0;
    
    do {
        c = getchar();

        if (c == EOF) {
            return 0;
        }

        if (c != '\n') {
            *output = c;
            num_chars++;
        }

    }while (c != '\n');

    return num_chars == 1;
}

void
print_menu()
{
    printf("1) Add Card\n");
    printf("2) Delete Card\n");
    printf("3) Print Cards\n");
    printf("4) Exit\n");
}

void
run_action(char item, int * finish)
{
    switch (item) {
        case '1':
            break;

        case '2':
            break;

        case '3':
            break;
        
        default:
            *finish = 1;
    }
}

int
main(int argc, char ** argv)
{
    char item;
    int finish;

    finish = 0;
    do{

        print_menu();

        while (!read_char(&item)) {
            fprintf(stderr, "[ERROR] Invalid reading!\n");
        }

        if (itemOk(item)) {
            run_action(item, &finish);
            printf("Run action!\n");
        } else {
            fprintf(stderr, "[ERROR] Invalid input!\n");
        }

    }while (!finish);

    exit(EXIT_SUCCESS);
}