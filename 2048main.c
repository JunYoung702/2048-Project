#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 4
typedef struct _2048tiles
{
    int tiles[SIZE][SIZE];
    struct *_2048tiles;
}tile;

bool wincounter = false;
bool status = false;
int numbers[SIZE][SIZE];
int score;
int zeros;
void draw(int score)
{
    for (int i = 0; i < SIZE; ++i)
    {
        printf("-------------------------\n");
        printf("|     |     |     |     |\n");
        printf("| %4d| %4d| %4d| %4d|\n", numbers[i][0], numbers[i][1], numbers[i][2], numbers[i][3]);
        printf("|     |     |     |     |\n");
    }
    printf("-------------------------");
    printf("\nScore: %d\n", score);
}
int move_left(void);
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
    numbers[x][y] = 2;
}
void rotate_left(void);
int merge(void);
int main(void)
{
    char command;
    // get input
    for (int i = 0; i < SIZE; ++i)
        scanf("%d %d %d %d", &numbers[i][0], &numbers[i][1], &numbers[i][2], &numbers[i][3]);
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            if (numbers[i][j] == 0)
                zeros++;
    // TODO: win, lose, merge + move_left into one function 
    draw(score);
    while (scanf("%c", &command) != EOF)
    {
        if (command == ' ' || command == '\n')
            continue;
        switch (command)
        {
        case 'a':
            move_left();
            score += merge();
            break;

        case 'w':
            rotate_left();
            move_left();
            score += merge();
            rotate_left();
            rotate_left();
            rotate_left();
            break;

        case 's':
            rotate_left();
            rotate_left();
            rotate_left();
            move_left();
            score += merge();
            rotate_left();
            break;

        case 'd':
            rotate_left();
            rotate_left();
            move_left();
            score += merge();
            rotate_left();
            rotate_left();
            break;

        default:
            break;
        }
        if (zeros > 0)
            number();
        draw(score);
        if (wincounter == true && status == false)
        {
            printf("you win!");
            status == true;
        }
        if (zeros == 16)
        {
            // Lose counter
        }
    }
    return 0;
}
int move_left(void)
{
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            for (int k = 0; k < j; ++k)
                if (numbers[i][k] == 0)
                {
                    int temp = numbers[i][k];
                    numbers[i][k] = numbers[i][j];
                    numbers[i][j] = temp;
                }
}
int merge(void)
{
    int scoreadded = 0;
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE - 1; ++j)
            if (numbers[i][j] == numbers[i][j + 1])
            {
                numbers[i][j] *= 2;
                scoreadded += numbers[i][j];
                numbers[i][j + 1] = 0;
                zeros++;
                if (numbers[i][j] == 2048)
                    wincounter = true;
            }
    move_left();
    return scoreadded;
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