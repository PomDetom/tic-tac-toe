#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3

//�����屾��
void game(char board[ROW][COL]);

//��ʼ��
void initial(char board[ROW][COL]);

//��ӡ����
void output(char board[ROW][COL]);

//�������
void player_action(char board[ROW][COL]);

//��������
void computer_action(char board[ROW][COL]);

//�ж�ʤ��
int judge(char board[ROW][COL]);
