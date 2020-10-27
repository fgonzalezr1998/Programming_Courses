#include <stdlib.h>
#include <stdio.h>

typedef struct CellType CellType;
struct CellType {
    int num;
    CellType * next;
};

typedef struct ListType ListType;
struct ListType {
    CellType * first;
};

void
push(ListType * list, int n)
{
    CellType * cell;

    // Allocate memory:

    cell = (CellType *)malloc(sizeof(CellType));
    cell->num = n;
    cell->next = NULL;

    if (list->first == NULL) {
        list->first = cell;
    } else {
        cell->next = list->first;
        list->first = cell;
    }
}

void
delete_list(ListType * list)
{
    // Free memory:

    CellType * c = list->first;
    while(c != NULL) {
        list->first = c->next;
        free(c);
        c = list->first;
    }
}

int
main(int argc, char * argv[])
{
    ListType list;

    list.first = NULL;

    for(int i = 0; i < 10; i++) {
        push(&list, i);
    }

 
    CellType * c = list.first;
    while(c != NULL) {
        printf("%d\n", c->num);
        c = c->next;
    }

    delete_list(&list);

    exit(EXIT_SUCCESS);
}