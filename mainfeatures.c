#include "./mainfeatures.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 4
extern bool wincounter;
extern bool status;
extern int score, zeros, moveable;
extern int numbers[SIZE][SIZE];
void draw(int score)
{
    for (int i = 0; i < SIZE; ++i)
    {
        printf("-------------------------\n");
        printf("|     |     |     |     |\n");
        printf("|%5d|%5d|%5d|%5d|\n", numbers[i][0], numbers[i][1], numbers[i][2], numbers[i][3]);
        printf("|     |     |     |     |\n");
    }
    printf("-------------------------");
    printf("\nScore: %d\n", score);
}
void number(void)
{
    srand(time(NULL));
    int x = rand() % SIZE;
    int y = rand() % SIZE;
    while (numbers[x][y] != 0)
    {
        if (rand() % 2 == 0)
            x++;
        else
            y++;
    }
    int z = rand() % 10;
    if (z == 0)
        numbers[x][y] = 4;
    else
        numbers[x][y] = 2;
    zeros--;
}
void rotate_left(void)
{
    int temp[SIZE][SIZE];
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            temp[i][j] = numbers[i][j];
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            numbers[i][j] = temp[j][SIZE - 1 - i];
}
int move_left(int arr[SIZE][SIZE])
{
    int scoreadded = 0;
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            for (int k = 0; k < j; ++k)
                if (arr[i][k] == 0 && arr[i][j] > 0)
                {
                    int temp = arr[i][k];
                    arr[i][k] = arr[i][j];
                    arr[i][j] = temp;
                    moveable++;
                }
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE - 1; ++j)
            if (arr[i][j] == arr[i][j + 1])
            {
                arr[i][j] *= 2;
                scoreadded += arr[i][j];
                arr[i][j + 1] = 0;
                zeros++;
                if (arr[i][j] == 2048)
                    wincounter = true;
            }
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            for (int k = 0; k < j; ++k)
                if (arr[i][k] == 0 && arr[i][j] > 0)
                {
                    int temp = arr[i][k];
                    arr[i][k] = arr[i][j];
                    arr[i][j] = temp;
                    moveable++;
                }
    return scoreadded;
}
int move_up(int arr[SIZE][SIZE])
{
    int temp;
    rotate_left();
    temp = move_left(arr);
    rotate_left();
    rotate_left();
    rotate_left();
    return temp;
}
int move_down(int arr[SIZE][SIZE])
{
    int temp;
    rotate_left();
    rotate_left();
    rotate_left();
    temp = move_left(arr);
    rotate_left();
    return temp;
}
int move_right(int arr[SIZE][SIZE])
{
    int temp;
    rotate_left();
    rotate_left();
    temp = move_left(arr);
    rotate_left();
    rotate_left();
    return temp;
}
