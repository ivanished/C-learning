#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

// 游戏主体
void game()
{
    // 存储数据
    char board[ROW][COL];
    // 初始化棋盘
    InitBoard(board, ROW, COL);
    // 打印棋盘
    DisplayBoard(board, ROW, COL);
    char ret = 0; // 接受游戏返回状态
    while (1)
    {
        // 玩家下棋
        PlayerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        
        //判断游戏状态
        ret = IsWin(board, ROW, COL);
        if (ret != 'C')
            break;
        
        // 电脑下棋
        ComputerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);

        //判断游戏状态
        ret = IsWin(board, ROW, COL);
        if (ret != 'C')
            break;
    }
    if (ret == '*')
    {
        printf("玩家赢！\n");
    }
    else if (ret == '#')
    {
        printf("电脑赢！\n");
    }
    else
    {
        printf("平局！\n");
    }
    DisplayBoard(board, ROW, COL);
}

int main() {
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu(); // 打印菜单
        printf("请选择:>");
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

