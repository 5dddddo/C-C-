#include "Coffee.h"
#include <iostream>
using namespace std;

Coffee::Coffee()
{
}


Coffee::~Coffee()
{
}


void Coffee::brew()
{
	cout << "커피를 내립니다." << endl;
}
void Coffee::addCondiment()
{
	cout << "커피에 밀크와 설탕을 첨가합니다." << endl;
}