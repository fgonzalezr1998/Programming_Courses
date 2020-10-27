#include "my_list/my_list.h"

int
isEmpty(ListType * list)
{
    return list == NULL;
}

void
push(ListType * list, CardType card)
{
    if (isEmpty(list)) {
        printf("Empty list");
    } else {
        printf("Not empty list");
    }
}