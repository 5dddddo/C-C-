#include <iostream>
using namespace std;
class Time{
private:
	int hour;
	int min;
public:
	Time();
	Time(int, int);
	//Time(double);
	//Time(const Time &tr);
	//Time plus(const Time &tr);
	Time operator+(const Time &br);
	Time operator-();
	Time &operator++();
	Time operator++(int);
	friend ostream &operator<<(ostream &os, Time &br);
	friend istream &operator>>(istream &is, Time &br);
	Time Time::operator*(int);
	friend void show(const Time &br);
	//void setHour(int);
	//int getHour();
	//void setMin(int);
	//int getMin();
};
//Time Time:: operator+(const Time &br)
//{
//	int h, m;
//	h = hour + br.hour;
//	m = min + br.min;
//	if (m >= 60){
//		h += m / 60;
//		m = m % 60;
//	}
//	Time res(h, m);
//	return res;
//}
//Time Time::operator-()
//{
//	Time temp(-hour, -min);
//	return temp;
//}
//Time &Time::operator++()
//{
//	min++;
//	if (min == 60){
//		hour++;
//		min = 0;
//	}
//	return *this;
//}
//Time Time::operator++(int)
//{
//	Time temp(hour, min);
//	min++;
//	if (min == 60){
//		hour++;
//		min = 0;
//	}
//	return temp;
//}
Time Time::operator*(int n)
{
	int h, m;
	h = hour *n;
	m = hour *n;
	if (m >= 60)
	{
		h += m / 60;
		m = m % 60;
	}
	return Time(h, m);
}
void show(const Time &br)
{
	cout << br.hour << "시간 " << br.min << "분" << endl;
}
Time::Time() :hour(0), min(0)
{ }
Time::Time(int h, int m) : hour(h), min(m)
{/*
 while (1)
 {
 if (m <0 || m>59)
 {
 cout << "분을 다시 입력하세요 : ";
 cin >> m;
 }
 else
 {
 min = m; break;
 }
 }*/
}
//Time::Time(double time)
//{
//	double res;
//	hour = time / 1.0;
//	res = time - hour;
//	min = res * 60;
//}
//Time::Time(const Time &tr)
//{
//	hour = tr.hour;
//	min = tr.min;
//}
//Time Time::plus(const Time &tr)
//{
//	Time temp;
//	int res;
//	temp.hour = hour + tr.hour;
//	temp.min = min + tr.min;
//	res = temp.min / 60;
//	if (temp.min >= 60)
//	{
//		temp.hour += res;
//		temp.min = temp.min - (res * 60);
//	}
//	return temp;
//}
//void Time::setHour(int h)
//{
//	hour = h;
//}
//int Time::getHour()
//{
//	return hour;
//}
//void Time::setMin(int m)
//{
//	while (1)
//	{
//		if (m <0 || m>59)
//		{
//			cout << "분을 다시 입력하세요 : ";
//			cin >> m;
//		}
//		else
//		{
//			min = m; break;
//		}
//	}
//}
//int Time::getMin()
//{
//	return min;
//}
void func(Time &br);
Time operator*(int n, Time &a);
ostream &operator<<(ostream &os, Time &br);
istream &operator>>(istream &is, Time &br);

//void Time::operator<<(ostream &os)
//{
//	os << hour << "시간 " << min << "분" << endl;
//}
//void Time::operator>>(istream &is)
//{
//	is >> hour >> min;
//}
int main()
{
	Time a(2, 20),b(3,30);
	cout << a << b;
	show(a);
	return 0;
}
//void func(Time &br)
//{
//	br++;
//}
Time operator*(int n, Time &a)
{
	return a*n;
}
ostream &operator<<(ostream &os, Time &br)
{
	os << br.hour << "시간 " << br.min << "분" << endl;
	return os;
}
istream &operator>>(istream &is, Time &br)
{
	is >> br.hour >> br.min;
	return is;
}