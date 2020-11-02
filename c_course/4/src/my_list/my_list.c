#include "my_list/my_list.h"

int
is_empty(ListType * list)
{
    return list == NULL;
}

void
push(ListType * list, CardType card)
{
    if (is_empty(list)) {
        printf("Empty list");
    } else {
        printf("Not empty list");
    }
}