/* TODO: Undo & Redo, Setting Menu */
#include <stdio.h>
#include <stdlib.h>
#include "./mainfeatures.h"
#define SIZE 4
extern int undocounter;
extern int stacksize;
typedef struct tiles
{
    int tile[SIZE][SIZE];
    struct tiles *next;
} tiles;
extern tiles numbers;
extern tiles *bottom, *top;
void push(tiles xyz)
{
    if (stacksize == 0)
    {
        bottom = &xyz;
        top = &xyz;
        bottom->next = NULL;
        stacksize++;
    }
    else if (stacksize == 1)
    {
        /*
        temp->item = item;
        temp->next = bottom;
        top = temp;
        */
        top = &xyz;
        top->next = bottom;
        stacksize++;
        /*
               top = malloc(sizeof(tiles));
               top->next = bottom;
               top->item = item;
               stacksize++;
               printf("%d\n", item);
        */
        // printf("PUSH function: bottom: %d\n top: %d \n stacksize: %d\n", bottom->item, top->item, stacksize);
    }
    else
    {
        tiles *new = malloc(sizeof(tiles));
        /*
        new->next = top->next;
        top->next = new;
        */
        new = top;
        top = &xyz;
        top->next = new;
        stacksize++;
        // printf("PUSH function: bottom: %d\n top: %d \n stacksize: %d\n", bottom->item,top->item, stacksize);
    }
}
void pop()
{
    if (stacksize <= 0)
        return;
    else if (stacksize == 1)
        stacksize--;
    else
    {
        tiles *temp = top;
        &top = &(top->next);
        free(temp);
        stacksize--;
        // printf("POP function: bottom: %d \n top: %d \n stacksize: %d\n", bottom->item, top->item, stacksize);
    }
}
int isempty()
{
    if (stacksize == 0)
        return 1;
    else
        return 0;
}

void undo(void)
{
    int temp[SIZE][SIZE];
}
void redo(void)
{

}
/*
void peek()
{
    if (stacksize <= 0)
        puts("-1");
    else
        printf("%d\n", top->item);
}
*/
/*
void search(int item)
{
    bool tf = false;
    int position = 0;
    tiles *temp = top;
    if (stacksize == 0)
    {
        puts("-1");
        return;
    }
    while (position < stacksize)
    {
        if (temp->item == item)
        {
            tf = true;
            break;
        }
        temp = temp->next;
        position++;
    }
    if (tf)
        printf("%d\n", position);
    else
        puts("-1");
}
*/