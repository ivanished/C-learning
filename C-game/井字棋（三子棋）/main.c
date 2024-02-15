#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

// ��Ϸ����
void game()
{
    // �洢����
    char board[ROW][COL];
    // ��ʼ������
    InitBoard(board, ROW, COL);
    // ��ӡ����
    DisplayBoard(board, ROW, COL);
    char ret = 0; // ������Ϸ����״̬
    while (1)
    {
        // �������
        PlayerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        
        //�ж���Ϸ״̬
        ret = IsWin(board, ROW, COL);
        if (ret != 'C')
            break;
        
        // ��������
        ComputerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);

        //�ж���Ϸ״̬
        ret = IsWin(board, ROW, COL);
        if (ret != 'C')
            break;
    }
    if (ret == '*')
    {
        printf("���Ӯ��\n");
    }
    else if (ret == '#')
    {
        printf("����Ӯ��\n");
    }
    else
    {
        printf("ƽ�֣�\n");
    }
    DisplayBoard(board, ROW, COL);
}

int main() {
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu(); // ��ӡ�˵�
        printf("��ѡ��:>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("Exit game!\n");
            break;
        default:
            printf("Error!\n");
            break;
        }
    } while(input);
    return 0;
}

