#include <iostream>
#include <string.h>
#pragma warning (disable:4996)
using namespace std;
class MoneyBox{
private:
	char *name;
	int sum;
public:
	MoneyBox();
	MoneyBox(const char *np, int m = 0);
	MoneyBox(const MoneyBox &br);
	~MoneyBox();
	MoneyBox  &operator =(const MoneyBox &br);
	void save(int m);
	void use(int m);
	void prn();
};

MoneyBox::MoneyBox()
{
	this->name = new char[strlen("아무개") + 1];
	strcpy(this->name, "아무개");
	this->sum = 0;
	//	cout << "디폴트 생성자 호출 " << this->name << endl;
}
MoneyBox::MoneyBox(const char *np, int m)
{
	this->name = new char[strlen(np) + 1];
	strcpy(this->name, np);
	this->sum = m;
	//	cout << "오버로디드 생성자 호출 " << this->name << endl;
}
MoneyBox::MoneyBox(const MoneyBox &br)
{
	this->name = new char[strlen(br.name) + 1];
	strcpy(this->name, br.name);
	this->sum = br.sum;
	//cout << "복사 생성자 호출 " << this->name << endl;
}
MoneyBox &MoneyBox::operator =(const MoneyBox &br)
{
	if (this == &br) return *this;
	delete[]name;
	name = new char[strlen(br.name) + 1];
	strcpy(name, br.name);
	sum = br.sum;
	return *this;
}

void MoneyBox::save(int m)
{
	if (m >= 0) { this->sum += m; }
}
void MoneyBox::use(int m)
{
	if (m > 0 && m <= this->sum) { this->sum -= m; }
}
void MoneyBox::prn()
{
	cout << "이름 : " << this->name << endl;
	cout << "잔액 : " << this->sum << endl;
}

MoneyBox::~MoneyBox()
{
	//cout << "destructer 수행 : " << this->name << endl;
	delete[] this->name;
}
//MoneyBox func(MoneyBox m);
MoneyBox& func(MoneyBox &m);

int main()
{
	//예제2-2
	//MoneyBox a;
	//MoneyBox b("홍길동");
	//MoneyBox c("이순신", 500);
	//MoneyBox d = b;
	//MoneyBox *mp1 = new MoneyBox("홍길동");
	//MoneyBox *mp2 = new MoneyBox(c);
	//func(b);
	//delete mp1; //동적메모리 해제하면서 destructer 호출
	//delete mp2; //동적메모리 해제하면서 destructer 호출

	//예제3-1
	MoneyBox a("철이", 100), b("메텔", 500), temp;
	a.prn();
	b.prn();
	temp = a;
	a = b;
	b = temp;
	a.prn();
	b.prn();
	a = b = temp;
	a = a;

	return 0;
}

//MoneyBox func(MoneyBox m)  // m = b 복사생성자 호출
//{
//	return m; //return하면서 m이 없어짐
//			  //MoneyBox type을 return하기 위해 임시 객체 m'이 생성되어 m' = m 복사생성자 호출됨
//}
MoneyBox& func(MoneyBox &m)  // m 그대로 갖다 씀
{
	return m; //MoneyBox& type이므로 이름을 return 
	//호출(2) + 소멸(2) 과정이 줄어들어 속도 향상 
}
