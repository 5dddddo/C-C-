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
	this->name = new char[strlen("�ƹ���") + 1];
	strcpy(this->name, "�ƹ���");
	this->sum = 0;
	//	cout << "����Ʈ ������ ȣ�� " << this->name << endl;
}
MoneyBox::MoneyBox(const char *np, int m)
{
	this->name = new char[strlen(np) + 1];
	strcpy(this->name, np);
	this->sum = m;
	//	cout << "�����ε�� ������ ȣ�� " << this->name << endl;
}
MoneyBox::MoneyBox(const MoneyBox &br)
{
	this->name = new char[strlen(br.name) + 1];
	strcpy(this->name, br.name);
	this->sum = br.sum;
	//cout << "���� ������ ȣ�� " << this->name << endl;
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
	cout << "�̸� : " << this->name << endl;
	cout << "�ܾ� : " << this->sum << endl;
}

MoneyBox::~MoneyBox()
{
	//cout << "destructer ���� : " << this->name << endl;
	delete[] this->name;
}
//MoneyBox func(MoneyBox m);
MoneyBox& func(MoneyBox &m);

int main()
{
	//����2-2
	//MoneyBox a;
	//MoneyBox b("ȫ�浿");
	//MoneyBox c("�̼���", 500);
	//MoneyBox d = b;
	//MoneyBox *mp1 = new MoneyBox("ȫ�浿");
	//MoneyBox *mp2 = new MoneyBox(c);
	//func(b);
	//delete mp1; //�����޸� �����ϸ鼭 destructer ȣ��
	//delete mp2; //�����޸� �����ϸ鼭 destructer ȣ��

	//����3-1
	MoneyBox a("ö��", 100), b("����", 500), temp;
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

//MoneyBox func(MoneyBox m)  // m = b ��������� ȣ��
//{
//	return m; //return�ϸ鼭 m�� ������
//			  //MoneyBox type�� return�ϱ� ���� �ӽ� ��ü m'�� �����Ǿ� m' = m ��������� ȣ���
//}
MoneyBox& func(MoneyBox &m)  // m �״�� ���� ��
{
	return m; //MoneyBox& type�̹Ƿ� �̸��� return 
	//ȣ��(2) + �Ҹ�(2) ������ �پ��� �ӵ� ��� 
}
