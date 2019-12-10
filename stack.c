#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int size = 0;
typedef struct stack
{
    int item;
    struct stack *next;
} Stack;
Stack *bottom, *top;
void push(int item);
void pop();
void isempty();
void peek();
void search(int item);
int main(void)
{
    bottom = top = calloc(1, sizeof(Stack));
    char command[15];
    int item;
    while (scanf("%s", command) != EOF)
    {
        if (command[0] == 'P')
        {
            if (command[1] == 'E')
                peek();
            else if (command[1] == 'U')
            {
                scanf("%d", &item);
                push(item);
            }
            else
                pop();
        }
        else if (command[0] == 'I')
            isempty();
        else if (command[0] == 'S')
        {
            scanf("%d", &item);
            search(item);
        }
    }
    // free(bottom);
    return 0;
}
void push(int item)
{
    if (size == 0)
    {
        bottom->item = item;
        printf("%d\n", item);
        size++;
        // printf("PUSH function: bottom: %d\n size: %d\n", bottom->item, size);
    }
    else if (size == 1)
    {
        Stack *lol = malloc(sizeof(Stack));
        lol->item = item;
        lol->next = bottom;
        top = lol;
        size++;
        printf("%d\n", item);
        /*
               top = malloc(sizeof(Stack));
               top->next = bottom;
               top->item = item;
               size++;
               printf("%d\n", item);
        */
        // printf("PUSH function: bottom: %d\n top: %d \n size: %d\n", bottom->item, top->item, size);
    }
    else
    {
        Stack *new = malloc(sizeof(Stack));
        new->next = top->next;
        top->next = new;
        new->item = top->item;
        top->item = item;
        printf("%d\n", item);
        size++;
        // printf("PUSH function: bottom: %d\n top: %d \n size: %d\n", bottom->item,top->item, size);
    }
}
void pop()
{
    if (size <= 0)
        puts("-1");
    else if (size == 1)
    {
        size--;
        printf("%d\n", bottom->item);
    }
    else
    {
        printf("%d\n", top->item);
        Stack *temp = top;
        top = top->next;
        // free(temp);
        size--;
        // printf("POP function: bottom: %d \n top: %d \n size: %d\n", bottom->item, top->item, size);
    }
}
void peek()
{
    if (size <= 0)
        puts("-1");
    else
        printf("%d\n", top->item);
}
void search(int item)
{
    bool tf = false;
    int position = 0;
    Stack *temp = top;
    if (size == 0)
    {
        puts("-1");
        return;
    }
    while (position < size)
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
void isempty()
{
    if (size == 0)
        printf("Y\n");
    else
        printf("N\n");
}
