#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3

//三子棋本体
void game(char board[ROW][COL]);

//初始化
void initial(char board[ROW][COL]);

//打印棋盘
void output(char board[ROW][COL]);

//玩家下棋
void player_action(char board[ROW][COL]);

//电脑下棋
void computer_action(char board[ROW][COL]);

//判断胜负
int judge(char board[ROW][COL]);
