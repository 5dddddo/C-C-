#include <iostream>
#include <string>
#include "Profile.h"
using namespace std;
void userScreen(void);
char menu(void);
void proInput(Profile *, int &);
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
	Profile  ary[20];   // 프로필 저장 객체 배열
	int profileCnt = 0;     // 입력 받은 프로필의 개수 카운트 변수
	char ch;          // 메뉴번호 저장 변수 

	while (1)
	{
		ch = menu();        // 입력된 메뉴의 번호를 ch에 리턴받음
		if (ch == '4') { break; }  // 4번 종료하기 메뉴 입력시 무한반복문을 탈출
		switch (ch)
		{
		case '1': proInput(ary, profileCnt); break;
		case '2': proUpdate(ary, profileCnt); break;
		case '3': proDisplay(ary, profileCnt); break;
		}
	}
}
//----------------------------------------------------------------------------------------------
char menu(void)
{
	char n = 0, i;
	char menulist[4][20] = { "프로필 입력", "프로필 수정", "프로필 출력", "종료" };

	for (i = 0; i < 4; i++)   // 메뉴 문자열을 출력하는 반복문
	{
		cout << i + 1 << ". " << menulist[i] << endl;
	}

	while (n<'1' || n>'4') // 유효한 번호가 아니면 다시 입력
	{
		cout << "* Select menu No. : _\b";
		cin >> n;
	}
	return(n);
}
//--------------------------------------------------------------------------------------------
void proInput(Profile *ap, int &cnt)
{
	string name,addr;
	int age;
	double height;

	while (1)
	{
		if (cnt < 20)
		{
			cout << "이름입력 : ";
			cin >> name;
			if (name == "끝") { break; }
			cout << "주소입력 : ";		cin >> addr;
			cout << "나이입력 : ";		cin >> age;
			cout << "키입력 : ";		cin >> height;
			ap[cnt] = Profile(name, addr, age, height); // 입력 받은 데이터로 객체 초기화
			cnt++;
		}
		else { cout << "입력 불가" << endl; break; }
	}
}
void proUpdate(Profile *ap, int cnt)
{
	string tempStr;
	char update[4][10] = { "이름", "주소", "나이", "신장" };
	int tempA, num;
	double tempH;
	while (1)
	{
		cout << "수정할 사람의 이름 입력 : ";
		cin >> tempStr;
		if (tempStr ==  "끝") { break; }
		for (int i = 0; i < cnt; i++)
		{
			if (ap[i].getName() ==  tempStr)
			{
				cout << "수정 전 Profile : " << ap[i].getName()<< "/"
					<< ap[i].getAddr()<< "/" << ap[i].getAge() << "세/"
					<< ap[i].getHeight() << "cm" << endl;
				cout << "수정 항목 선택(1.이름/2.주소/3.나이/4.신장) : ";
				cin >> num;
				while (cin.fail() || (num <1 || num > 4))
				{
					cin.clear();
					while (cin.get() == '\n');
					cout << "수정 항목 선택(1.이름/2.주소/3.나이/4.신장) : ";
					cin >> num;
				}
				cout << "수정할 ";
				switch (num)
				{
				case 1: cout << update[0] << "을 입력하세요 : ";
					cin >> tempStr; ap[i].setName(tempStr); break;
				case 2: cout << update[1] << "를 입력하세요 : ";
					cin >> tempStr; ap[i].setAddr(tempStr); break;
				case 3: cout << update[2] << "를 입력하세요 : ";
					cin >> tempA; ap[i].setAge(tempA); break;
				case 4: cout << update[3] << "을 입력하세요 : ";
					cin >> tempH; ap[i].setHeight(tempH); break;
				}
				cout << "수정 후 Profile : " << ap[i].getName() << " : "
					<< ap[i].getAddr() << "/" << ap[i].getAge() << "세/"
					<< ap[i].getHeight() << "cm" << endl;
				break;
			}
			if (ap[i].getName() == tempStr && i == cnt - 1)
				cout << "검색 실패" << endl;
		}
	}
}
void proDisplay(Profile *ap, int cnt)
{
	int i;
	for (i = 0; i < cnt; i++)
	{
		cout << i + 1 << ". " << ap[i].getName() << " : "
			<< ap[i].getAddr() << "/" << ap[i].getAge() << "세/"
			<< ap[i].getHeight() << "cm" << endl;
	}
}

