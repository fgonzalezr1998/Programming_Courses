/*
 * Implements a double linked list of 'CardType' as LIFO
 */

#include "my_list/my_list.h"
#include <string.h>

#define MAXSTR 10

void print_card(CardType card);

int
is_empty(ListType list)
{
    return list.first == NULL;
}

void
push(ListType * list, CardType card)
{
    /*
     * Input 'card' element into the list
     */

    CellType *cell;

    // Allocate memory for the new cell and save the card:

    cell = (CellType *)malloc(sizeof(CellType));
    cell->card = card;

    if (is_empty(*list)) {
        cell->next = NULL;
        cell->prev = NULL;
        list->first = cell;
        list->last = cell;
        list->size = 1;
    } else {
        // Add as a stack

        cell->next = list->first;
        cell->prev = NULL;
        list->first->prev = cell;
        list->first = cell;
        list->size++;
    }
}

void
pop(ListType * list, CardType * card)
{
    /*
     * Pop one element from the list
     */

    CellType *aux;

    memcpy(card, &(list->first->card), sizeof(CardType));

    aux = list->first;
    list->first = list->first->next;
    if (list->first != NULL)
        list->first->prev = NULL;
    else
        list->last = NULL;

    list->size--;

    free(aux);
}

void
delete_list(ListType * list)
{
    /*
     * Delete all the list
     */

    CellType *aux_cell;

    aux_cell = list->first;
    while (aux_cell != NULL) {
        list->first = aux_cell->next;
        free(aux_cell);
        aux_cell = list->first;
    }
}

void
print_list(ListType list)
{
    CardType card;
    CellType * cell_ptr;

    if (is_empty(list))
        return;

    cell_ptr = list.first;
    for(int i = 0; i < list.size; i++) {
        card = cell_ptr->card;
        print_card(card);
        cell_ptr = cell_ptr->next;
    }
}

void
print_card(CardType card)
{
    char suit[MAXSTR];

    switch (card.suit) {
        case Espadas:
            strncpy(suit, "Espadas", sizeof(char) * MAXSTR);
            break;
        case Copas:
            strncpy(suit, "Copas", sizeof(char) * MAXSTR);
            break;
        case Oros:
            strncpy(suit, "Oros", sizeof(char) * MAXSTR);
            break;
        case Bastos:
            strncpy(suit, "Bastos", sizeof(char) * MAXSTR);
            break;
        default:
            ;
    }

    printf("%d de %s\n", card.value, suit);
}
