#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <err.h>
#include "my_list/my_list.h"

#define MAXSTR 10
#define MINCARDVALUE 1
#define MAXCARDVALUE 12

int
itemOk(int c)
{
    return c >= '1' && c <= '4';
}

int
value_ok(int value)
{
    return value >= MINCARDVALUE && value <= MAXCARDVALUE;
}

int
is_int(char * s)
{
    /*
     * Returns if 's' string is an integer
     */

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] < '0' || s[i] > '9') {
            return 0;
        }
    }

    return 1;
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
str_upper(char * s)
{
    for (int i = 0; i < strlen(s); i++) {
        // If is lower...

        if (s[i] <= 'z' && s[i] >= 'a') {

            // Change to upper:

            s[i] = s[i] - ('a' - 'A');
        }
    }
}

int
get_suit(SuitType * suit)
{
    char str[MAXSTR];

    if (fgets(str, MAXSTR, stdin) == NULL) {
        fprintf(stderr, "[ERROR] Invalid reading!\n");
        return 0;
    }
    str[strlen(str) - 1] = '\0';    // Delete the '\n' char from the string

    str_upper(str);

    if (strcmp(str, "ESPADAS") == 0) {
        *suit = (SuitType)0;
    } else if (strcmp(str, "COPAS") == 0) {
        *suit = (SuitType)1;
    } else if (strcmp(str, "OROS") == 0) {
        *suit = (SuitType)2;
    } else if (strcmp(str, "BASTOS") == 0) {
        *suit = (SuitType)3;
    } else {
        return 0;
    }

    return 1;
}

int
get_value(int * value)
{
    char str[MAXSTR];
    int n;

    if (fgets(str, MAXSTR, stdin) == NULL) {
        fprintf(stderr, "[ERROR] Invalid reading!\n");
        return 0;
    }
    str[strlen(str) - 1] = '\0';    // Delete the '\n' char from the string

    if (is_int(str)) {
        n = atoi(str);
    } else {
        return 0;
    }

    if (!value_ok(n)) {
        return 0;
    }

    *value = n;

    return 1;
}

int
get_card(CardType * card)
{
    /*
     * Store the new card in 'card'
     */

    SuitType suit;
    int value;

    printf("%s", "Suit: ");

    // Get the suit:

    if (!get_suit(&suit)) {
        return 0;
    }

    printf("%s", "Value: ");

    // Read the value:

    if (!get_value(&value)) {
        return 0;
    }

    card->suit = suit;
    card->value = value;
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
add_card(ListType * list)
{
    // Get a card and add it to the double linked list

    CardType card;

    while (!get_card(&card)) {
        fprintf(stderr, "[ERROR] Invalid card!\n");
    }

    // Now, I have the card saved at 'card':

    push(list, card);
}

void
delete_card(ListType * list)
{
    CardType *card = (CardType*)malloc(sizeof(CardType));

    pop(list, card);

    printf("Card deleted:\n");
    print_card(*card);

    free(card);
}

void
run_action(char item, int * finish, ListType * list)
{
    switch (item) {
        case '1':
            add_card(list);
            break;

        case '2':
            delete_card(list);
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

    ListType list = {
        .first = NULL,
        .last = NULL,
        .size = 0,
    };

    finish = 0;
    do{

        print_menu();

        while (!read_char(&item)) {
            fprintf(stderr, "[ERROR] Invalid reading!\n");
        }

        if (itemOk(item)) {
            run_action(item, &finish, &list);
            printf("-----------\n");
        } else {
            fprintf(stderr, "[ERROR] Invalid input!\n");
        }

    } while (!finish);

    print_list(list);

    delete_list(&list);

    exit(EXIT_SUCCESS);
}
