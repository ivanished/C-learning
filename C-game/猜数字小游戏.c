#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//��ȷ��Ҫʵ�ֵ�Ŀ������дһ����������Ϸ��
//
//1.����һ��1 - 100֮����������
//
//2.�������ֽ��в����֡�
//
//- a.�¶��ˣ���ʾ����ϲ�����ˡ�����Ϸ������
//
//- b.�´��ˣ���ʾ���ֲµĴ��ˣ����ǲµ�С�ˣ������£�ֱ���¶�Ϊֹ��
//
//3.��Ϸ��������Խ�����һ�ּ����£�����ѡ���˳���Ϸ��

// ����Menu
void menu()
{
	printf("*********************\n");
	printf("******* 1.play ******\n");
	printf("******* 0.exit ******\n");
	printf("*********************\n");
}

// ������Ϸ����
void game()
{
	int num = rand() % 100 + 1; // rand()�������������ģ100���ص�ֵ��Χ��0-99����ʱ�ټ�1���صľ���1-100
	int guess = 0;
	while (1)
	{
		printf("�������:>");
		scanf("%d", &guess);
		if (guess > num)
		{
			printf("�´��ˣ�\n");
		}
		else if (guess < num)
		{
			printf("��С�ˣ�\n");
		}
		else
		{
			printf("��ϲ�����¶��ˣ�\n");
			break;
		}
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL)); // ͨ��ʱ����������������
	do
	{
		menu(); // ��ӡ��Ϸ�˵�
		printf("��ѡ��:>", input);
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ERROR������������\n");
			break;
		}

	} while (input);
}