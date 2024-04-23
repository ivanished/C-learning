#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set) {
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++) {
			for (j = 0; j < cols; j++) {
				board[i][j] = set;
			}
		}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col) {
	int i = 0;
	int j = 0;
	printf("-----------扫雷游戏-----------\n");
	// 打印列号
	for (i = 0; i <= col; i++) {
			printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++) {
		printf("%d ", i);
		for (j = 1; j <= col; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-----------扫雷游戏-----------\n");
}


void SetMine(char board[ROWS][COLS], int row, int col, int count) {
	// 在棋盘上布置雷
	while (count) {
			int x = rand() % row + 1;
			int y = rand() % col + 1;
			if (board[x][y] == '0') {
				board[x][y] = '1';
				count--;
			}
		}
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	// 1.输入排查的坐标
	// 2.判断坐标是不是雷
	//   2.1 如果是雷，游戏结束
	//   2.2 如果不是雷，统计周围雷的个数
	// 3.展示给用户
	int x = 0;
	int y = 0;
	int count = 0;
	int win = 0;
	while (win<row*col-EASY_COUNT) {
		printf("请输入排查的坐标:>");
		scanf("%d %d", &x, &y); // 坐标范围 x: 1-9 y: 1-9
		// 判断坐标合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (mine[x][y] == '1') {
				printf("很遗憾，你被炸死了\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else {
				// 不是雷的情况下，统计周围雷的个数
				count = mine[x - 1][y - 1] +
					mine[x - 1][y] +
					mine[x - 1][y + 1] +
					mine[x][y - 1] +
					mine[x][y + 1] +
					mine[x + 1][y - 1] +
					mine[x + 1][y] +
					mine[x + 1][y + 1] - 8 * '0';
				show[x][y] = count + '0';
				win++;
				// 显示排查的信息
				DisplayBoard(show, ROW, COL);
			}
		}
		else {
			printf("坐标非法,请重新输入\n");
		}

		if (win == row * col - EASY_COUNT)
			printf("恭喜你，排雷成功\n");
			DisplayBoard(mine, ROW, COL);
	}	
}