#include "./lib-cross.h"
#include "./mainfeatures.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 4
bool wincounter = false;
bool status = false;
int losecounter;
int numbers[SIZE][SIZE];
int score;
int zeros;
typedef struct _2048tiles
{
    int tiles[SIZE][SIZE];
    struct _2048tiles *next;
} tile;
int main(void)
{
    hide_cursor();
    char command;
    // get input
    for (int i = 0; i < SIZE; ++i)
        scanf("%d %d %d %d", &numbers[i][0], &numbers[i][1], &numbers[i][2], &numbers[i][3]);
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            if (numbers[i][j] == 0)
                zeros++;
    draw(score);
    while ((command = getch()) != EOF)
    {
        if (command == ' ' || command == '\n')
            continue;
        if (command == EOF)
            break;
        switch (command)
        {
        case 'a':
            screen_clear();
            score += move_left(numbers);
            break;

        case 'w':
            screen_clear();
            score += move_up(numbers);
            break;

        case 's':
            screen_clear();
            score += move_down(numbers);
            break;

        case 'd':
            screen_clear();
            score += move_right(numbers);
            break;

        default:
            break;
        }
        if (zeros > 0)
            number();
        draw(score);
        if (wincounter == true && status == false)
        {
            printf("You Win!");
            status == true;
        }
        if (zeros == 0) // Test losing condition
        {
            int temp[SIZE][SIZE];
            for (int i = 0; i < SIZE; ++i)
                for (int j = 0; j < SIZE; ++j)
                    temp[i][j] = numbers[i][j];
            losecounter += move_left(temp);
            for (int i = 0; i < SIZE; ++i)
                for (int j = 0; j < SIZE; ++j)
                    temp[i][j] = numbers[i][j];
            losecounter += move_down(temp);
            for (int i = 0; i < SIZE; ++i)
                for (int j = 0; j < SIZE; ++j)
                    temp[i][j] = numbers[i][j];
            losecounter += move_right(temp);
            for (int i = 0; i < SIZE; ++i)
                for (int j = 0; j < SIZE; ++j)
                    temp[i][j] = numbers[i][j];
            losecounter += move_up(temp);
            if (!losecounter)
            {
                printf("You Lose!");
                break;
            }
        }
    }
    show_cursor();
    return 0;
}
