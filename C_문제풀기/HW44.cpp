#pragma warning(disable:4996)
#include <time.h> //_strtime()�� ���ؼ� ��Ŭ��� �� 
#include<windows.h> // strtok(), atoi()�� ���ؼ� ��Ŭ��� �� 
#include<stdio.h> 
static int count;
struct time{
	unsigned int ti_hour;
	unsigned int ti_min;
	unsigned int ti_sec;
};
void gettime(struct time *);
void gotoxy(int x, int y);
int timer(struct time *,int *);
void main()
{
	int i = 0;
	int res;
	struct time sttime;
	while (1)
	{
		gettime(&sttime);
		res = timer(&sttime, &i);
		if (res)
		{
			if (i == 10)
			{
				return;
			}
			gotoxy(30, 12);
			printf("%u �� %u �� %u�� \n", sttime.ti_hour, sttime.ti_min, sttime.ti_sec);
		}
	}
}
int timer(struct time *t, int* i)
{
	static int sec = t->ti_sec;
	if (t->ti_sec == sec)
	{
		return 0;
	}
	else
	{
		*i++;
		return 1;
	}
}
void gettime(struct time *p) // ���� �����͸� ��ȯ�Ҽ� �ֵ��� Call by pointer ��� ��� 
{

	char temp[30];
	char *cp;
	_strtime(temp); // temp char�迭 �ȿ� 00:00:00(��:��:��)���� ���ڿ� ���·� ���� 

	cp = strtok(temp, ":"); // temp�迭�� ù��° ':'���� ���ڿ��� ����� cp���� �ÿ� �ش��ϴ� ���ڿ��� �����ּҸ� ���� 

	p->ti_hour = atoi(cp); // ��� �ÿ� �ش��ϴ� ���ڿ��� ������ �����ͷ� ��ȯ�Ͽ� p->ti_hour�� ���� 

	cp = strtok(NULL, ":"); // temp�迭�� �ι�° ':'���� ���ڿ��� ����� cp���� �п� �ش��ϴ� ���ڿ��� �����ּҸ� ���� 

	p->ti_min = atoi(cp); // ��� �п� �ش��ϴ� ���ڿ��� ������ �����ͷ� ��ȯ�Ͽ� p->ti_min�� ���� 

	cp = strtok(NULL, ":"); // temp�迭�� ����° ':'���� ���ڿ��� ������ϳ� ':'�� ��Ÿ���� �ʰ� ���ڿ��� 
	// ������ �ǹǷ� ���� ���ڿ� ��ü�� �����Ѵ� ��, cp���� �ʿ� �ش��ϴ� ���ڿ��� �����ּҰ� �����Ѵ�. 

	p->ti_sec = atoi(cp); // ��� �ʿ� �ش��ϴ� ���ڿ��� ������ �����ͷ� ��ȯ�Ͽ� p->ti_sec�� ���� 
}

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}