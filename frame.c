#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

//�˵�
void menu()
{
	printf("******************************\n");
	printf("**********1.��ʼ��Ϸ**********\n");
	printf("**********0.�˳���Ϸ**********\n");
	printf("******************************\n");
}

//��Ϸ
void game(char board[ROW][COL])
{
	initial(board);//��ʼ��
	output(board);//��ӡ����

	while (1)
	{
		player_action(board);//�������
		output(board);
		int ret = judge(board);
		if (ret == 1)//�ж�ʤ��
		{
			printf("���ʤ��\n");
			break;
		}
		if (ret == 0)
		{
			printf("ƽ�֡�\n");
			break;
		}
		
		computer_action(board);//��������
		output(board);
		ret = judge(board);
		if (ret == 1)
		{
			printf("����ʤ��\n");
			break;
		}
		if (ret == 0)
		{
			printf("ƽ�֡�\n");
			break;
		}
	}
}

int main()
{
	int pick = 0;
	char board[ROW][COL] = { 0 };
	srand((unsigned int)time(NULL));
	//�˵�
	do
	{
		menu();
		scanf("%d", &pick);

		switch (pick)
		{
		case 1:
			printf("��ʼ��Ϸ\n");
			game(board);//������Ϸ11
			break;
		case 0:
			break;//�˳���Ϸ
		default:
			printf("���Ϸ�������ѡ��\n");
		}
	} while (pick);

	return 0;
}