#include <iostream>
#include <time.h> 
#include<windows.h> 
#include<stdio.h> 
#pragma warning (disable: 4996)
struct date {
	unsigned int da_year;
	unsigned int da_mon;
	unsigned int da_day;
};
using namespace std;
struct Goods
{
	char item[50];
	int price;
	int year;
	int mon;
	int day;
	int discount;
};
void input(Goods &s);
void selling_price(Goods &s);
void prn(const Goods &s);
int tot_days(int y, int m, int d);
int leap_check(int year);
void getdate(struct date *);

int main()
{
	Goods good;
	input(good);
	selling_price(good);
	prn(good);
	return 0;
}
void input(Goods &s)
{
	cout << "ǰ�� �Է� : ";
	cin.getline(s.item, sizeof(s.item));
	cout << "���� �Է� : ";
	cin >> s.price;
	cout << "������� �Է� : ";
	if (s.discount != 0)
		cin >> s.year >> s.mon >> s.day;
	else cout << "��������� �������ϴ�!" << endl;
}
void selling_price(Goods &s)
{
	date state;
	int today, sDay, res;
	getdate(&state);
	sDay = tot_days(s.year, s.mon, s.day);
	if (sDay != 0)
	{
		today = tot_days(state.da_year, state.da_mon, state.da_day);
		res = sDay - today;
		if (res <0) s.discount = 100;
		else if (res >= 0 && res <= 3) s.discount = 50;
		else if (res > 3 && res <= 10) s.discount = 20;
		else s.discount = 0;
	}
	else s.discount = 0;
}
void prn(const Goods &s)
{
	cout << "ǰ�� : " << s.item << endl;
	cout << "�ǸŰ� : " << (1 - s.discount / 100.0) * s.price << endl;
	cout << "������� : " << s.year << "-" << s.mon << "-" << s.day << endl;
	cout << "������ : " << s.discount << "%" << endl;
}
int tot_days(int y, int m, int d)
{
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int totYear = 0, totMon = 0, totDay = 0, i, res;
	if (leap_check(y) == 1 && (month[3] < d || month[5] < d || month[8] < d || month[10] < d))
	{
		cout << "��������� �߸� �Է��ϼ̽��ϴ�. " << endl;
		fflush(stdin);
		return 0;
	}
	else if (leap_check(y) == 1);
	else if (month[m - 1] < d)
	{
		cout << "��������� �߸� �Է��ϼ̽��ϴ�. " << endl;
		fflush(stdin);
		return 0;
	}
	for (i = 1; i <= y - 1; i++)
	{
		res = leap_check(i);
		if (res == 1) totYear += 366;
		else totYear += 365;
	}
	for (i = 0; i < m - 1; i++)
		totMon += month[i];
	totDay = totYear + totMon + d;
	if (res == 1 && m >= 3)
		totDay++;
	return totDay;
}
int leap_check(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) return 1;
	else return 0;
}
void getdate(struct date *p) // ���� �����͸� ��ȯ�Ҽ� �ֵ��� Call by pointer ��� ��� 
{
	char temp[128];
	char *cp, syear[5] = "20";
	_strdate(temp); // temp char�迭 �ȿ� 08/10/04(��/��/��)������ ������� ���ڿ� ���·� ���� 
	cp = strtok(temp, "/"); // temp�迭�� ù��° '/'���� ���ڿ��� ����� cp���� "08" ���ڿ��� �����ּҸ� ���� 
	p->da_mon = atoi(cp); // ��� "08"���ڿ��� ������ ������ 8�� ��ȯ�Ͽ� p->da_mon�� ���� 
	cp = strtok(NULL, "/"); // temp�迭�� �ι�° '/'���� ���ڿ��� ����� cp���� "10" ���ڿ��� �����ּҸ� ���� 
	p->da_day = atoi(cp); // ��� "10"���ڿ��� ������ ������ 10�� ��ȯ�Ͽ� p->da_day�� ���� 
	cp = strtok(NULL, "/"); // temp�迭�� ����° '/'���� ���ڿ��� ������ϳ� '/'�� ��Ÿ���� �ʰ� ���ڿ��� 
	// ������ �ǹǷ� ���� ���ڿ� ��ü�� �����Ѵ� ��, cp���� "04" ���ڿ��� �����ּҰ� �����Ѵ�. 
	strcat(syear, cp); // syear���� "20"�� cp�� ����Ű�� "04"�� �ٿ��� "2004" ���ڿ��� syear������ ���� 
	p->da_year = atoi(syear); // syear���� "2004" ���ڿ��� ������ ������ 2004�� ��ȯ�Ͽ� p->da_year�� ���� 
}
