#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// ��������
#define ROW 3
#define COL 3

// �˵�����
void menu();

// ��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);

// ��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col);

// �������
void PlayerMove(char board[ROW][COL], int row, int col);

// ��������
void ComputerMove(char board[ROW][COL], int row, int col);

// �ж���Ϸ״̬
char IsWin(char board[ROW][COL], int row, int col);

// �ж������Ƿ�����
int IsFull(char board[ROW][COL], int row, int col);