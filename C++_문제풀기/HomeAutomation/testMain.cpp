#include "LightAutomation.h"
#include "LightFixture.h"
#include <iostream>
using namespace std;
void screen(LightAutomation &r);
int menu(char **menuList, int menuCnt);
void displayTitle(string title);
void listDisplayAppliance(LightAutomation &r);
void controlAppliance(LightAutomation &r);
void addAppliance(LightAutomation &r);
void deleteAppliance(LightAutomation &r);
int main()
{
	LightAutomation homeAuto;
	homeAuto.initLightAutomation();
	screen(homeAuto);
	return 0;
}

void screen(LightAutomation &r)
{
	char *menuList[5] =
	{ "1.���� ����Ȯ��", "2.���� ����", "3.���� ���", "4.���� ����", "5.����" };
	int menuCnt, menuNum = 0;

	cout << "\n------------------------------\n"
		<< "    Ȩ ���� �ɾ�ý��� ����\n"
		<< "------------------------------";
	while (menuNum != 5)
	{
		for (menuCnt = 0; menuCnt < 5; menuCnt++)
			menuNum = menu(menuList, menuCnt);
		switch (menuNum)
		{
		case 1: listDisplayAppliance(r); break;
		case 2: controlAppliance(r); break;
		case 3: addAppliance(r); break;
		case 4: deleteAppliance(r); break;
		case 5: break;
		}
	}

}
int menu(char **menuList, int menuCnt)
{
	int num;
	if (menuCnt == 0) cout << "\n\n==================================\n"
		<< menuList[menuCnt] << endl;
	else if (menuCnt == 1) cout << menuList[menuCnt] << endl;
	else if (menuCnt == 2) cout << menuList[menuCnt] << endl;
	else if (menuCnt == 3) cout << menuList[menuCnt] << endl;
	else
	{
		cout << menuList[menuCnt] << endl;
		cout << "==================================\n"
			<< "# �޴���ȣ�� �Է��ϼ��� : ";
		cin >> num;
		while (cin.fail() || (num < 1 || num >> 5))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "# �޴���ȣ�� �Է��ϼ��� : ";
			cin >> num;
		}
		return num;
	}
}
void displayTitle(string title)
{
	cout << "\n------------------------------\n"
		<< "    " << title
		<< "\n------------------------------" << endl;

}
void listDisplayAppliance(LightAutomation &r)
{
	displayTitle("���� ���� ����");
	if (r.getLightCnt() == 0)
		cout << "��ϵ� ������ �����ϴ�." << endl;
	else
		r.listDisplayAppliance();
	displayTitle("���� ���� ���� ����");
}
void controlAppliance(LightAutomation &r)
{
	LightFixture temp;
	string name; bool res;
	displayTitle("���� ���� �ϱ�");
	if (r.getLightCnt() == 0)
		cout << "��ϵ� ������ �����ϴ�. ������ ���� ����ϼ���." << endl;
	else
	{
		cout << "* ������ ����� �Է� : ";
		cin >> name;
		res = r.controlAppliance(name);
		if (res == true) cout << "����� : " << name << "�� ��� �Ϸ�Ǿ����ϴ�." << endl;
		else cout << "** �ش��ϴ� ��ǰ�� �������� �ʽ��ϴ�."
			<< "����� : " << name << "�� ��� �����Ͽ����ϴ�." << endl;
	}
}
void addAppliance(LightAutomation &r)
{
	LightFixture temp;
	string name; bool res;
	displayTitle("���� ��� �ϱ�");
	cout << "* ��ǰ�� �Է�( ��)�Ž�����, �ȹ�� ��) : ";
	cin >> name;
	temp.setMachineName(name);
	res = r.addAppliance(temp);
	if (res == true) cout << "����� : " << name << "�� ����� �Ϸ�Ǿ����ϴ�." << endl;
	else cout << "����� : " << name << "�� ����� �����Ͽ����ϴ�." << endl;
}
void deleteAppliance(LightAutomation &r)
{
	string name; bool res;
	displayTitle("���� �����ϱ�");
	cout << "* ����� �Է�( ��)�Ž�����, �ȹ�� ��) : ";
	cin >> name;
	res = r.deleteAppliance(name);
	if (res == true) cout << "����� : " << name << "�� ������ �Ϸ�Ǿ����ϴ�." << endl;
	else cout << "����� : " << name << "�� ������ �����Ͽ����ϴ�." << endl;

}