#include "./mainfeatures.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 4
extern bool bwinChecker;
extern bool status;
extern int score, zeros;
extern int numbers[SIZE][SIZE];

void Draw(int score)
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

void SetNum(void)
{
	srand(time(NULL));
	int x = rand() % SIZE;
	int y = rand() % SIZE;
	while (numbers[x][y] != 0)
	{
		if (rand() % 2 == 0)
			x = (x + 1) % SIZE;
		else
			y = (y + 1) % SIZE;
	}
	if (rand() % 10 == 0)
		numbers[x][y] = 4;
	else
		numbers[x][y] = 2;
	--zeros;
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
	int scoreAdded = 0;
	/* move without merge code */
	/* Merge code */
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			for (int k = 0; k < j; ++k)
			{
				if (arr[i][k] == 0 && arr[i][j] > 0)
				{
					int temp = arr[i][k];
					arr[i][k] = arr[i][j];
					arr[i][j] = temp;
				}
			}
		}
		for (int j = 0; j < SIZE; ++j)
		{
			if (j < SIZE - 1)
			{
				if (arr[i][j] > 0 && arr[i][j] == arr[i][j + 1])
				{
					arr[i][j] *= 2;
					arr[i][j + 1] = 0;
					scoreAdded += arr[i][j];
					++zeros;
					if (arr[i][j] == 2048)
					{
						bwinChecker = true;
					}
				}
			}
		}
		for (int j = 0; j < SIZE; ++j)
		{
			for (int k = 0; k < j; ++k)
			{
				if (arr[i][k] == 0 && arr[i][j] > 0)
				{
					int temp = arr[i][k];
					arr[i][k] = arr[i][j];
					arr[i][j] = temp;
				}
			}
		}
	}
	return scoreAdded;
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
