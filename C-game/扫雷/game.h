#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2 // 为了方便处理边界，多加一行一列
#define COLS COL+2 

#define EASY_COUNT 10

// 初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

// 打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col);

// 布置雷
void SetMine(char board[ROWS][COLS], int row, int col, int count);

// 排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);