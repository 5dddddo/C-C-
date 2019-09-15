#pragma warning(disable:4996)
#include <time.h> //_strtime()를 위해서 인클루드 함 
#include<windows.h> // strtok(), atoi()를 위해서 인클루드 함 
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
			printf("%u 시 %u 분 %u초 \n", sttime.ti_hour, sttime.ti_min, sttime.ti_sec);
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
void gettime(struct time *p) // 원본 데이터를 변환할수 있도록 Call by pointer 기법 사용 
{

	char temp[30];
	char *cp;
	_strtime(temp); // temp char배열 안에 00:00:00(시:분:초)순의 문자열 상태로 저장 

	cp = strtok(temp, ":"); // temp배열의 첫번째 ':'까지 문자열를 끊어내어 cp에게 시에 해당하는 문자열의 시작주소를 리턴 

	p->ti_hour = atoi(cp); // 끊어낸 시에 해당하는 문자열을 정수형 데이터로 변환하여 p->ti_hour에 저장 

	cp = strtok(NULL, ":"); // temp배열의 두번째 ':'까지 문자열를 끊어내어 cp에게 분에 해당하는 문자열의 시작주소를 리턴 

	p->ti_min = atoi(cp); // 끊어낸 분에 해당하는 문자열을 정수형 데이터로 변환하여 p->ti_min에 저장 

	cp = strtok(NULL, ":"); // temp배열의 세번째 ':'까지 문자열를 끊어내려하나 ':'은 나타나지 않고 문자열이 
	// 끝나게 되므로 남은 문자열 전체를 리턴한다 즉, cp에게 초에 해당하는 문자열의 시작주소가 리턴한다. 

	p->ti_sec = atoi(cp); // 끊어낸 초에 해당하는 문자열을 정수형 데이터로 변환하여 p->ti_sec에 저장 
}

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}