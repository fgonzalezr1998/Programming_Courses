#include <stdlib.h>
#include <stdio.h>

typedef enum SuitType SuitType;
enum SuitType {
    Espadas = 0,
    Copas,
    Oros,
    Bastos,
};

typedef struct CardType CardType;
struct CardType {
    SuitType suit;
    int value;
};

typedef struct CellType CellType;
struct CellType {
    CardType card;
    CellType *next;
    CellType *prev;
};

typedef struct ListType ListType;
struct ListType {
    CellType *first;
    CellType *last;
    int size;
};

void push(ListType * list, CardType card);
void delete_list(ListType * list);
void print_list(ListType list);
