#pragma warning(disable : 4996)

#include "./lib-cross.h"
#include "./mainfeatures.h"
#include <stdbool.h> //bool
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 4

// true
bool bwinChecker = false;
int numbers[SIZE][SIZE];
int score;
int zeroNum;

bool LoseCheck()
{
	for (int i = 0; i < SIZE-1; ++i)
	{
		for (int j = 0; j < SIZE-1; ++j)
		{
			if (numbers[i][j] == numbers[i + 1][j])
			{
				return false;
			}
			if (numbers[i][j] == numbers[i][j + 1])
			{
				return false;
			}
		}
		if (numbers[i][3] == numbers[i+1][3])
		{
			return false;
		}
		if (numbers[3][i] == numbers[3][i + 1])
		{
			return false;
		}
	}
	return true;
}

int main(void)
{
	//Initialize
	
	//consol set height width
	system("mode con: cols=30 lines=20"); //#include <stdlib.h>
	hide_cursor();
	srand(time(NULL));

	const int count = (rand() % 4) + 5;
	for (int i = 0; i < count; ++i)
	{
		SetNum();
	}
	zeros = 16 - count;
	Draw(score);

	//Input 
	char command = -1;
	while ((command = getch()) != EOF)
	{
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
			continue;
			break;//not using
		}

		if (zeros > 0)
		{
			SetNum();
		}

		Draw(score);

		if (bwinChecker == true)
		{
			printf("You Win!");
		}

		if (zeros == 0 && LoseCheck()) // Test losing condition
		{
			printf("You Lose!");
			break;
		}
	}
	show_cursor();
	
	return 0;
}
