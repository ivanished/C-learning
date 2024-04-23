#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void menu() {
	printf("**********************\n");
	printf("******  1.play  ******\n");
	printf("******  0.exit  ******\n");
	printf("**********************\n");
}

void game() {
	char mine[ROWS][COLS] = { 0 }; // 存放雷的信息
	char show[ROWS][COLS] = { 0 }; // 存放展示给用户的信息
	// 初始化
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	// 打印棋盘
	//DisplayBoard(show, ROW, COL);

	// 布置雷
	SetMine(mine, ROW, COL, EASY_COUNT);
	DisplayBoard(mine, ROW, COL);
	
	// 排查雷
	FindMine(mine, show, ROW, COL);
}

int main() {
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			printf("扫雷游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}