#include "Beverage.h"
#include <iostream>
using namespace std;

Beverage::Beverage()
{
}


Beverage::~Beverage()
{
}

void Beverage::make()
{
	boilWater();
	brew();
	pourInCup();
	addCondiment();
}

void Beverage::boilWater()
{
	cout << "���� ���Դϴ�." << endl;
}

void Beverage::pourInCup()
{
	cout << "�ſ� �����ϴ�." << endl;
}