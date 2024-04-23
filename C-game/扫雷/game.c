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
	printf("-----------ɨ����Ϸ-----------\n");
	// ��ӡ�к�
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
	printf("-----------ɨ����Ϸ-----------\n");
}


void SetMine(char board[ROWS][COLS], int row, int col, int count) {
	// �������ϲ�����
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
	// 1.�����Ų������
	// 2.�ж������ǲ�����
	//   2.1 ������ף���Ϸ����
	//   2.2 ��������ף�ͳ����Χ�׵ĸ���
	// 3.չʾ���û�
	int x = 0;
	int y = 0;
	int count = 0;
	int win = 0;
	while (win<row*col-EASY_COUNT) {
		printf("�������Ų������:>");
		scanf("%d %d", &x, &y); // ���귶Χ x: 1-9 y: 1-9
		// �ж�����Ϸ���
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (mine[x][y] == '1') {
				printf("���ź����㱻ը����\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else {
				// �����׵�����£�ͳ����Χ�׵ĸ���
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
				// ��ʾ�Ų����Ϣ
				DisplayBoard(show, ROW, COL);
			}
		}
		else {
			printf("����Ƿ�,����������\n");
		}

		if (win == row * col - EASY_COUNT)
			printf("��ϲ�㣬���׳ɹ�\n");
			DisplayBoard(mine, ROW, COL);
	}	
}