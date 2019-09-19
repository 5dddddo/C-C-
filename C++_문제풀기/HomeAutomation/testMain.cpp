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
	{ "1.전등 상태확인", "2.전등 제어", "3.전등 등록", "4.전등 삭제", "5.종료" };
	int menuCnt, menuNum = 0;

	cout << "\n------------------------------\n"
		<< "    홈 조명 케어시스템 시작\n"
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
			<< "# 메뉴번호를 입력하세요 : ";
		cin >> num;
		while (cin.fail() || (num < 1 || num >> 5))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "# 메뉴번호를 입력하세요 : ";
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
	displayTitle("전등 상태 보기");
	if (r.getLightCnt() == 0)
		cout << "등록된 전등이 없습니다." << endl;
	else
		r.listDisplayAppliance();
	displayTitle("전등 상태 보기 종료");
}
void controlAppliance(LightAutomation &r)
{
	LightFixture temp;
	string name; bool res;
	displayTitle("전등 제어 하기");
	if (r.getLightCnt() == 0)
		cout << "등록된 전등이 없습니다. 전등을 먼저 등록하세요." << endl;
	else
	{
		cout << "* 제어할 전등명 입력 : ";
		cin >> name;
		res = r.controlAppliance(name);
		if (res == true) cout << "전등명 : " << name << "의 제어가 완료되었습니다." << endl;
		else cout << "** 해당하는 제품이 존재하지 않습니다."
			<< "전등명 : " << name << "의 제어가 실패하였습니다." << endl;
	}
}
void addAppliance(LightAutomation &r)
{
	LightFixture temp;
	string name; bool res;
	displayTitle("전등 등록 하기");
	cout << "* 제품명 입력( 예)거실전등, 안방등 등) : ";
	cin >> name;
	temp.setMachineName(name);
	res = r.addAppliance(temp);
	if (res == true) cout << "전등명 : " << name << "의 등록이 완료되었습니다." << endl;
	else cout << "전등명 : " << name << "의 등록을 실패하였습니다." << endl;
}
void deleteAppliance(LightAutomation &r)
{
	string name; bool res;
	displayTitle("전등 삭제하기");
	cout << "* 전등명 입력( 예)거실전등, 안방등 등) : ";
	cin >> name;
	res = r.deleteAppliance(name);
	if (res == true) cout << "전등명 : " << name << "의 삭제가 완료되었습니다." << endl;
	else cout << "전등명 : " << name << "의 삭제가 실패하였습니다." << endl;

}