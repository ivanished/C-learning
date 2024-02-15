#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// 棋盘行列
#define ROW 3
#define COL 3

// 菜单函数
void menu();

// 初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);

// 打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

// 玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);

// 电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);

// 判断游戏状态
char IsWin(char board[ROW][COL], int row, int col);

// 判断棋盘是否填满
int IsFull(char board[ROW][COL], int row, int col);