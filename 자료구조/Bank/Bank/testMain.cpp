#pragma warning (disable: 4996)
#include "queue.h"
#include "datatype.h"
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
void printCustomer(DataType *p);
void gotoxy(int x, int y);
int main()
{
	int ch,i,jobNum,xCnt = 0;
	int waitNum = 0 , waitCustomer = 0, newCustomer;
	char task[3][8] = { "�Ա�", "���", "����" };
	DataType temp,endWait;
	Queue que;
	initQueue(&que, 21);
	srand((unsigned int)time(NULL)); //�ٸ� �����߻�
	while (1)
	{
		if (kbhit()) //key �Է� ���� �˻�, �Է������� return 1 
		{
			ch = getch();
			if (ch == 'e' || ch == '1' || ch == '2' || ch == '3' ||ch == 'x')
			{
				if (xCnt == 0)
				{
					if (ch == 'e')
					{
						newCustomer = rand() % 5 + 1;
						waitCustomer += newCustomer;
						if (waitCustomer > 20)
							waitCustomer = 20;
						for (i = 0; i != newCustomer; i++)
						{
							jobNum = rand() % 3 + 1;
							strcpy(temp.job, task[jobNum - 1]);
							waitNum++;
							temp.number = waitNum;
							if (!enqueue(&que, temp))
								waitNum--;
						}
					}
				}
				if (xCnt >= 0)
				{
					if (ch == '1' || ch == '2' || ch == '3')
					{
						if (dequeue(&que, &endWait))
						{
							if (waitCustomer > 0)
								waitCustomer--;
							else waitCustomer = 0;
							if (xCnt > 0 && waitCustomer == 0)
								break;
							if (ch == '1')
							{
								gotoxy(2, 18);
								printf("%2d : %s\n", endWait.number, endWait.job);
							}
							else if (ch == '2')
							{
								gotoxy(26, 18);
								printf("%2d : %s\n", endWait.number, endWait.job);
							}
							else
							{
								gotoxy(50, 18);
								printf("%2d : %s\n", endWait.number, endWait.job);
							}
						}
						else
							waitCustomer = 0;

						gotoxy(15, 15);
					}
					else if (ch == 'x')
					{
						xCnt++;
						gotoxy(49, 1);
						printf("���๮ ����\n");
						gotoxy(1, 23);
						if (xCnt > 0 && waitCustomer == 0)
							break;
					}
				}
			}
			else break;
		}

			gotoxy(1, 1);
		printf("����ο� : %2d", waitCustomer);
		gotoxy(1, 20);
		printf("������������		������������		������������\n");
		printf("��    1	  ��		��    2	  ��		��    3   ��\n");
		printf("������������		������������		������������\n");

	}
	return 0;
}

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
