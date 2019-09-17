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
	cout << "품목 입력 : ";
	cin.getline(s.item, sizeof(s.item));
	cout << "정가 입력 : ";
	cin >> s.price;
	cout << "유통기한 입력 : ";
	if (s.discount != 0)
		cin >> s.year >> s.mon >> s.day;
	else cout << "유통기한이 지났습니다!" << endl;
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
	cout << "품명 : " << s.item << endl;
	cout << "판매가 : " << (1 - s.discount / 100.0) * s.price << endl;
	cout << "유통기한 : " << s.year << "-" << s.mon << "-" << s.day << endl;
	cout << "할인율 : " << s.discount << "%" << endl;
}
int tot_days(int y, int m, int d)
{
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int totYear = 0, totMon = 0, totDay = 0, i, res;
	if (leap_check(y) == 1 && (month[3] < d || month[5] < d || month[8] < d || month[10] < d))
	{
		cout << "유통기한을 잘못 입력하셨습니다. " << endl;
		fflush(stdin);
		return 0;
	}
	else if (leap_check(y) == 1);
	else if (month[m - 1] < d)
	{
		cout << "유통기한을 잘못 입력하셨습니다. " << endl;
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
void getdate(struct date *p) // 원본 데이터를 변환할수 있도록 Call by pointer 기법 사용 
{
	char temp[128];
	char *cp, syear[5] = "20";
	_strdate(temp); // temp char배열 안에 08/10/04(월/일/년)순으로 년월일이 문자열 상태로 저장 
	cp = strtok(temp, "/"); // temp배열의 첫번째 '/'까지 문자열를 끊어내어 cp에게 "08" 문자열의 시작주소를 리턴 
	p->da_mon = atoi(cp); // 끊어낸 "08"문자열을 정수형 데이터 8로 변환하여 p->da_mon에 저장 
	cp = strtok(NULL, "/"); // temp배열의 두번째 '/'까지 문자열를 끊어내어 cp에게 "10" 문자열의 시작주소를 리턴 
	p->da_day = atoi(cp); // 끊어낸 "10"문자열을 정수형 데이터 10로 변환하여 p->da_day에 저장 
	cp = strtok(NULL, "/"); // temp배열의 세번째 '/'까지 문자열를 끊어내려하나 '/'은 나타나지 않고 문자열이 
	// 끝나게 되므로 남은 문자열 전체를 리턴한다 즉, cp에게 "04" 문자열의 시작주소가 리턴한다. 
	strcat(syear, cp); // syear내의 "20"과 cp가 가리키는 "04"을 붙여서 "2004" 문자열을 syear변수에 저장 
	p->da_year = atoi(syear); // syear내의 "2004" 문자열을 정수형 데이터 2004로 변환하여 p->da_year에 저장 
}
