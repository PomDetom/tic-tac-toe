#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

//菜单
void menu()
{
	printf("******************************\n");
	printf("**********1.开始游戏**********\n");
	printf("**********0.退出游戏**********\n");
	printf("******************************\n");
}

//游戏
void game(char board[ROW][COL])
{
	initial(board);//初始化
	output(board);//打印棋盘

	while (1)
	{
		player_action(board);//玩家下棋
		output(board);
		int ret = judge(board);
		if (ret == 1)//判断胜负
		{
			printf("玩家胜。\n");
			break;
		}
		if (ret == 0)
		{
			printf("平局。\n");
			break;
		}
		
		computer_action(board);//电脑下棋
		output(board);
		ret = judge(board);
		if (ret == 1)
		{
			printf("电脑胜。\n");
			break;
		}
		if (ret == 0)
		{
			printf("平局。\n");
			break;
		}
	}
}

int main()
{
	int pick = 0;
	char board[ROW][COL] = { 0 };
	srand((unsigned int)time(NULL));
	//菜单
	do
	{
		menu();
		scanf("%d", &pick);

		switch (pick)
		{
		case 1:
			printf("开始游戏\n");
			game(board);//进入游戏11
			break;
		case 0:
			break;//退出游戏
		default:
			printf("不合法，重新选择。\n");
		}
	} while (pick);

	return 0;
}