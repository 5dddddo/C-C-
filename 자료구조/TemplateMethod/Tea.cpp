#include "Tea.h"
#include <iostream>
using namespace std;

Tea::Tea()
{
}


Tea::~Tea()
{
}
void Tea::brew()
{
	cout << "홍차를 우려냅니다." << endl;
}
void Tea::addCondiment()
{
	cout << "레몬을 넣습니다." << endl;
}