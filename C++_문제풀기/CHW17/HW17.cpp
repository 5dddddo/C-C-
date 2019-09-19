#include <iostream>
using namespace std;
class Time
{
private:
	int hour;
	int min;
	double time;
	static int mode;
	enum { integer, real };
public:
	Time();
	Time(int, int);
	Time(double);
	Time(const Time &tr);
	Time plus(const Time &tr);
	void setHour(int);
	int getHour();
	void setMin(int);
	int getMin();
	friend ostream &operator<<(ostream &os, const Time &br);
	static void mode_change();
};
Time::Time() :hour(0), min(0), time(0.0)
{}
Time::Time(int h, int m) : hour(h), min(m)
{
	time = h;
	time += (double)min / 60;

}
Time::Time(double t)
{
	int temp;
	time = t;
	hour = (int)t;
	min = (t - hour) * 60;
}
Time::Time(const Time &tr) :hour(tr.hour), min(tr.min), time(tr.time)
{
	mode = tr.mode;
}
Time Time::plus(const Time &tr)
{
	Time temp;
	int res;
	temp.hour = hour + tr.hour;
	temp.min = min + tr.min;
	res = temp.min / 60;
	if (temp.min >= 60)
	{
		temp.hour += res;
		temp.min = temp.min - (res * 60);
	}
	return temp;

}
void Time::setHour(int h)
{
	int temp;
	hour = h;
	time = h / 1.0;
	time += (double)min / 60;
}
int Time::getHour()
{
	return hour;
}
void Time::setMin(int m)
{
	double t;
	min = m;
	time = (int)time;
	time += (double)m / 60;
}
int Time::getMin()
{
	return min;
}
ostream &operator<<(ostream &os, const Time &br)
{
	if (br.mode == br.integer) os << br.hour << "시간 " << br.min << "분";
	else os << br.time << "시간";
	return os;
}
void Time::mode_change()
{
	if (mode == integer) mode = real;
	else mode = integer;
}
int Time::mode = integer;
int main()
{
	Time a(3, 21);
	Time b(2.7);
	cout << "기본 출력 형태(시간,분)..." << endl;
	cout << a << endl;
	cout << b << endl;
	Time::mode_change();
	cout << "출력모드를 바꾼 후..." << endl;
	cout << a << endl;
	cout << b << endl;
	return 0;
}