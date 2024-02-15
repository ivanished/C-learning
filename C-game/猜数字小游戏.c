#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//先确定要实现的目标需求，写一个猜数字游戏。
//
//1.生成一个1 - 100之间的随机数。
//
//2.输入数字进行猜数字。
//
//- a.猜对了，提示“恭喜猜中了”，游戏结束。
//
//- b.猜错了，提示数字猜的大了，还是猜的小了，继续猜，直到猜对为止。
//
//3.游戏结束后可以进行下一轮继续猜，除非选择退出游戏。

// 定义Menu
void menu()
{
	printf("*********************\n");
	printf("******* 1.play ******\n");
	printf("******* 0.exit ******\n");
	printf("*********************\n");
}

// 定义游戏主体
void game()
{
	int num = rand() % 100 + 1; // rand()生成随机数进行模100返回的值范围在0-99，此时再加1返回的就是1-100
	int guess = 0;
	while (1)
	{
		printf("请猜数字:>");
		scanf("%d", &guess);
		if (guess > num)
		{
			printf("猜大了！\n");
		}
		else if (guess < num)
		{
			printf("猜小了！\n");
		}
		else
		{
			printf("恭喜您，猜对了！\n");
			break;
		}
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL)); // 通过时间戳设置随机数种子
	do
	{
		menu(); // 打印游戏菜单
		printf("请选择:>", input);
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("ERROR，请重新输入\n");
			break;
		}

	} while (input);
}