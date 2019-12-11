/* TODO: Undo & Redo, Setting Menu */
#include <stdio.h>
#include <stdlib.h>
#include "./mainfeatures.h"
#define SIZE 4
extern int undocounter;
typedef struct tiles
{
    int tile[SIZE][SIZE];
    struct tiles *next;
} tiles;
extern tiles numbers;
extern tiles *bottom, *top;
void push(int item);
void pop();
void isempty();
//void peek();
//void search(int item);
void undo(void);
void redo(void);