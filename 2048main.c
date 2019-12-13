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
int moveable;
int numbers[SIZE][SIZE];
int score;
int zeros;
int main(void)
{
    hide_cursor();
    char command;
    // get input
	srand(time(NULL));
	int count = (rand() % 4) + 5;
	for (int i = 0; i < count; ++i) 
		number();
	zeros = 16 - count;
    draw(score);
    while ((command = getch()) != EOF)
    {
		moveable = 0;
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
        if (zeros > 0 && moveable > 0)
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
