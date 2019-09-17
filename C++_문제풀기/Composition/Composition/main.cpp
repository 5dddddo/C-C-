 #include <iostream>
#include <string.h>
#include "Profile.h"
#include "MyString.h"
using namespace std;

void userScreen(void);
char menu(void);
void proInput(Profile *,int &);
void proUpdate(Profile *, int);
void proDisplay(Profile *, int);

int main()
{
	userScreen();
	return 0;
}
//----------------------------------------------------------------------------------------------
void userScreen()
{
	Profile  ary[20];   // ������ ���� ��ü �迭
	int profileCnt = 0;     // �Է� ���� �������� ���� ī��Ʈ ����
	char ch;          // �޴���ȣ ���� ���� 

	while (1)
	{
		ch = menu();        // �Էµ� �޴��� ��ȣ�� ch�� ���Ϲ���
		if (ch == '4') { break; }  // 4�� �����ϱ� �޴� �Է½� ���ѹݺ����� Ż��
		switch (ch)
		{
		case '1': proInput(ary,profileCnt); break;
		case '2' : proUpdate(ary,profileCnt); break;
		case '3': proDisplay(ary, profileCnt); break;
		}
	}
}
//----------------------------------------------------------------------------------------------
char menu(void)
{
	char n = 0, i;
	char menulist[4][20] = { "������ �Է�", "������ ����", "������ ���", "����" };

	for (i = 0; i<4; i++)   // �޴� ���ڿ��� ����ϴ� �ݺ���
	{
		cout << i + 1 << ". " << menulist[i] << endl;
	}

	while (n<'1' || n>'4') // ��ȿ�� ��ȣ�� �ƴϸ� �ٽ� �Է�
	{
		cout << "* Select menu No. : _\b";
		cin >> n;
	}
	return(n);
}
//--------------------------------------------------------------------------------------------
void proInput(Profile *ap,int &cnt)
{
	char name[50];
	char addr[80];
	int age;
	double height;
	
	while (1)
	{
		if (cnt < 20)
		{
			cout << "�̸��Է� : ";
			cin >> name;
			if (strcmp(name, "��") == 0) { break; }
			cout << "�ּ��Է� : ";		cin >> addr;
			cout << "�����Է� : ";		cin >> age;
			cout << "Ű�Է� : ";		cin >> height;
			ap[cnt] = Profile(name, addr, age, height); // �Է� ���� �����ͷ� ��ü �ʱ�ȭ
			cnt++;
		}
		else { cout << "�Է� �Ұ�" << endl; break; }
	}
}
void proUpdate(Profile *ap, int cnt)
{
	char tempStr[100];
	char update[4][10] = { "�̸�", "�ּ�", "����", "����" };
	int tempA, num;
	double tempH;
	while (1)
	{
		cout << "������ ����� �̸� �Է� : ";
		cin >> tempStr;
		if (strcmp(tempStr, "��") == 0) { break; }
		for (int i = 0; i < cnt; i++)
		{
			if (strcmp(ap[i].getName().getStr(), tempStr) == 0)
			{
				cout << "���� �� Profile : " << ap[i].getName().getStr() << "/"
					<< ap[i].getAddr().getStr() << "/" << ap[i].getAge() << "��/"
					<< ap[i].getHeight() << "cm" << endl;
				cout << "���� �׸� ����(1.�̸�/2.�ּ�/3.����/4.����) : ";
				cin >> num;
				while (cin.fail() || (num <1 || num > 4))
				{
					cin.clear();
					while (cin.get() == '\n');
					cout << "���� �׸� ����(1.�̸�/2.�ּ�/3.����/4.����) : ";
					cin >> num;
				}
				cout << "������ ";
				switch (num)
				{
				case 1: cout << update[0] << "�� �Է��ϼ��� : "; 
					cin >> tempStr; ap[i].setName((MyString)tempStr); break;
				case 2: cout << update[1] << "�� �Է��ϼ��� : ";
					cin >> tempStr; ap[i].setAddr((MyString)tempStr); break;
				case 3: cout << update[2] << "�� �Է��ϼ��� : ";
					cin >> tempA; ap[i].setAge(tempA); break;
				case 4: cout << update[3] << "�� �Է��ϼ��� : ";
					cin >> tempH; ap[i].setHeight(tempH); break;
				}
				cout << "���� �� Profile : " << ap[i].getName().getStr() << " : "
					<< ap[i].getAddr().getStr() << "/" << ap[i].getAge() << "��/"
					<< ap[i].getHeight() << "cm" << endl;
				break;
			}
			if (strcmp(ap[i].getName().getStr(), tempStr) != 0 && i == cnt - 1)
				cout << "�˻� ����" << endl;
		}
	}
}
void proDisplay(Profile *ap, int cnt)
{
	int i;
	for (i = 0; i<cnt; i++)
	{
		cout << i + 1 << ". " << ap[i].getName().getStr() << " : "
			<< ap[i].getAddr().getStr() << "/" << ap[i].getAge() << "��/"
			<< ap[i].getHeight() << "cm" << endl;
	}
}

