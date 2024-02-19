#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

//初始化
void initial(char board[ROW][COL])
{
	int i = 0;

	for (i = 0; i < ROW; i++)
	{
		int j = 0;
		for (j = 0; j < COL; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//打印棋盘
void output(char board[ROW][COL])
{
	int i = 0;

	for (i = 0; i < ROW; i++)
	{
		int j = 0;
		for (j = 0; j < COL; j++)
		{
			printf(" %c ", board[i][j]);
			if (j != COL - 1)
			{ 
				printf("|");
			}
			else
			{
				printf("\n");
			}
		}

		int k = 0;
		if (i < ROW - 1)
		{
			for (k = 0; k < COL; k++)
			{
				if (k != COL)
				{
					printf("---");
				}
				if (k != COL - 1)
				{
					printf("|");
				}
				else
				{
					printf("\n");
				}
			}
		}
	}
}

//玩家下棋
void player_action(char board[ROW][COL])
{
	int a = 0;
	int b = 0;

	while (1)
	{
		printf("玩家下棋，请输入坐标（如1 1，2 3）：");
		scanf("%d %d", &a, &b);

		if (a <= ROW && a > 0 && b <= COL && b > 0)
		{
			if (board[a - 1][b - 1] == ' ')
			{
				board[a - 1][b - 1] = '*';
				break;
			}
			else
			{
				printf("坐标占用，重新输入。\n");
			}
		}
		else
		{
			printf("坐标非法，重新输入。\n");
		}
	}
}

//电脑下棋
void computer_action(char board[ROW][COL])
{
	int a = 0;
	int b = 0;

	printf("电脑下棋：\n");
	while (1)
	{
		a = rand() % ROW;
		b = rand() % COL;
		if (board[a][b] == ' ')
		{
			board[a][b] = '#';
			break;
		}
	}
}

//判断胜负
int judge(char board[ROW][COL])
{
	int a = 0;
	int b = 0;

	for (a = 0; a < ROW; a++)//判断行
	{
		if (board[a][b] != ' ')
		{
			if (board[a][b] == board[a][b + 1] && board[a][b] == board[a][b + 2])
			{
				return 1;
			}
		}
	}

	for (a = 0; a < COL; a++)//判断列
	{
		if (board[b][a] != ' ')
		{
			if (board[b][a] == board[b + 1][a] && board[b][a] == board[b + 2][a])
			{
				return 1;
			}
		}
	}

	//判断对角
	if (a = 0, b = 0, board[a][b] != ' ')
	{
		if (board[a][b] == board[a + 1][b + 1] && board[a][b] == board[a + 2][b + 2])
		{
			return 1;
		}
	}
	if (a = 0, b = 0, board[a][b + 2] != ' ')
	{
		if (board[a][b + 2] == board[a + 1][b + 1] && board[a][b + 2] == board[a + 2][b])
		{
			return 1;
		}
	}

	//判断平局
	for (a = 0; a < ROW; a++)
	{
		for (b = 0; b < COL; b++)
		{
			if (board[a][b] == ' ')
			{
				return 2;
			}
		}
	}
	return 0;
}
