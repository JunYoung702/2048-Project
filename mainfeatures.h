#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 4
extern bool wincounter;
extern bool status;
extern int score, zeros, moveable;
extern int numbers[SIZE][SIZE];
void rotate_left(void);
int move_left(int arr[SIZE][SIZE]);
void number(void);
void draw(int score);
int move_up(int arr[SIZE][SIZE]);
int move_down(int arr[SIZE][SIZE]);
int move_right(int arr[SIZE][SIZE]);