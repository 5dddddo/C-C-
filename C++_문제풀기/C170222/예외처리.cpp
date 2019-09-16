
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string.h>

#pragma warning (disable: 4996)
class Test{
private:
	char str[80];
public:
	Test(const char *s) { strcpy(str, s); }
	~Test(){ cout << str << "객체의 소멸자 호출.." << endl; }
};

int mod1(int x, int y);
int mod2(int x, int y);

int main()
{
	int a, b, res;

	cout << "두 정수 입력 : ";
	cin >> a >> b;
	try{
		res = mod2(a, b);
	}
	catch (char *s){
		cout << s << endl;
		exit(1);
	}
	cout << "몫의 두 배 : " << res << endl;

	cin.get();
	cin.get();
	return 0;
}

int mod2(int x, int y)
{
	Test a("mod2");
	int r;

	r = 2 * mod1(x, y);
	return r;
}

int mod1(int x, int y)
{
	Test a("mod1");
	if (y == 0){
		throw "0으로 나눌 수 없습니다.";
	}
	return x / y;
}

